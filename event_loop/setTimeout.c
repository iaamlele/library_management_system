#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

//setTimeout(func, time)
typedef void (*func_ptr)(void *);
// typedef struct timeout_args {
//     func_ptr fun;
//     int time;
//     void *arg;
// } *TimeoutArgs;

//每setTimeout就要创建一个线程,开销太大->线程池管理线程->队列存储任务
typedef struct task {
    func_ptr func;
    void *arg;
    struct task *next;
} *Task;

//处理事件的队列
typedef struct task_queue {
    struct task *first;
    struct task *last;
    pthread_mutex_t mux; //创建互斥锁  初始化时不要变成初始化指针:pthread_mutex mux  
    pthread_cond_t cond; //创建条件变量
} *TaskQueue;

//线程池
typedef struct thread_pool {
    pthread_t *thread_arr;
    int count;
    TaskQueue queue;
    int stop;
} *ThreadPool;

TaskQueue init_queue() {
    TaskQueue queue = (TaskQueue)malloc(sizeof(struct task_queue));
    queue->first = queue->last = NULL;
    pthread_mutex_init(&queue->mux, NULL); //初始化互斥锁    Q1 ,,&
    pthread_cond_init(&queue->cond, NULL); //初始化条件变量    Q2
    return queue;
}

void enqueue(ThreadPool threadpool, func_ptr func, void *arg) {
    Task task = (Task)malloc(sizeof(struct task));
    task->func = func;
    task->arg = arg;
    task->next = NULL;

    pthread_mutex_lock(&threadpool->queue->mux); //拿到互斥锁,进入临界区
    if(threadpool->queue->first == NULL) {
        threadpool->queue->first = threadpool->queue->last = task;
    }else {
        threadpool->queue->last->next = task;
        threadpool->queue->last = threadpool->queue->last->next;
    }
    pthread_cond_signal(&threadpool->queue->cond); // 通知等待在条件变量上的消费者
    pthread_mutex_unlock(&threadpool->queue->mux); //释放互斥锁
}

Task dequeue(ThreadPool threadpool) {       //Q4正确退出
    pthread_mutex_lock(&threadpool->queue->mux); //拿到互斥锁,进入临界区
    while(threadpool->queue->first == NULL && threadpool->stop) {  //Q3 while  +  条件
        pthread_cond_wait(&threadpool->queue->cond, &threadpool->queue->mux); //没有任务,进程等待条件变量
    }   

    if(!threadpool->stop) {
        pthread_mutex_unlock(&threadpool->queue->mux);
        return NULL;
    }

    Task task = threadpool->queue->first;
    threadpool->queue->first = threadpool->queue->first->next;
    if(threadpool->queue->first == NULL) {
        threadpool->queue->last = NULL;
    }
    
    pthread_mutex_unlock(&threadpool->queue->mux);//释放互斥锁
    return task;
}

//线程池工作机制
void *thread_work(void *threadpool) {//从任务队列中获取任务并执行
    ThreadPool threadpool1 = (ThreadPool)threadpool;
    while(1) {
        Task task = dequeue(threadpool1);   //Q5 封装性
        if(task == NULL) {
            if(!threadpool1->stop) {
                break;
            }
            continue;
        }
        task->func(task->arg);
        free(task);
    }
    pthread_exit(NULL);
    return NULL;
}

ThreadPool init_thread_pool(int thread_count, TaskQueue queue) {
    ThreadPool threadpool = (ThreadPool)malloc(sizeof(struct thread_pool));

    threadpool->thread_arr = (pthread_t *)malloc(sizeof(pthread_t) * thread_count);
    threadpool->count = thread_count;
    threadpool->queue = queue;
    threadpool->stop = 1; //1未停止, 0停止

    for(int i = 0; i < threadpool->count; i++) {
        pthread_create(&threadpool->thread_arr[i], NULL, thread_work, (void *)threadpool); //?函数是是什么,这个函数要从任务队列中获取任务并执行
    }

    return threadpool;
}

void destroy_thread_pool_and_queue(ThreadPool threadpool) {
    pthread_mutex_lock(&threadpool->queue->mux);
    threadpool->stop = 0; //停止
    pthread_cond_broadcast(&threadpool->queue->cond);
    pthread_mutex_unlock(&threadpool->queue->mux);

    for(int i = 0; i < threadpool->count; i++) {
        pthread_join(threadpool->thread_arr[i], NULL);
    }
    free(threadpool->thread_arr);
    free(threadpool->queue);
    free(threadpool);
}

void my_func(void *arg) {
    int *my_func_arg = (int *)arg;
    printf("my_func arg is:%d\n", *my_func_arg);
}

// void *thread_func(void *args) {
//     TimeoutArgs timeoutArgs = (TimeoutArgs)args;
//     timeoutArgs->fun(timeoutArgs->arg);
//     free(timeoutArgs);
//     return NULL;
// }

// void setTimeout(func_ptr fun, int time, void *arg) {
//     TimeoutArgs args = (TimeoutArgs)malloc(sizeof(struct timeout_args));
//     args->fun = fun;
//     args->time = time;
//     args->arg = arg;

//     pthread_t thread;
    
//     pthread_create(&thread, NULL, thread_func, args);
//     sleep(time); //以秒为单位
//     pthread_join(thread, NULL);
// }

int main() {
    // int arg = 1;
    // setTimeout(my_func, 1, &arg);
    TaskQueue queue = init_queue();
    ThreadPool threadpool = init_thread_pool(2, queue);
    threadpool->queue = queue;

    int arg1 = 1;
    int arg2 = 2;
    enqueue(threadpool, my_func, &arg1);
    enqueue(threadpool, my_func, &arg2);

    sleep(0.5);

    destroy_thread_pool_and_queue(threadpool);


    return 0;
}