#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include <unistd.h>

typedef void (*func_ptr)(void *);

typedef struct task {
    func_ptr func;
    void *arg;
    struct task *next;
} *Task;

typedef struct queue {
    struct task *first;
    struct task *last;
    pthread_mutex_t mtx;
    pthread_cond_t cond;
} *TaskQueue;

TaskQueue init_queue() {
    TaskQueue queue = (TaskQueue)malloc(sizeof(struct queue));
    queue->first = queue->last = NULL;
    pthread_mutex_init(&queue->mtx, NULL);
    pthread_cond_init(&queue->cond, NULL);
    return queue;
}

void enqueue(TaskQueue queue, func_ptr func, void *arg) {
    Task task = (Task)malloc(sizeof(struct task));
    task->func = func;
    task->arg = arg;
    task->next = NULL;

    pthread_mutex_lock(&queue->mtx);
    if(queue->first == NULL) {
        queue->first = queue->last = task;
    }else {
        queue->last->next = task;
        queue->last = queue->last->next;
    }
    pthread_cond_signal(&queue->cond);
    pthread_mutex_unlock(&queue->mtx);
}

Task dequeue(TaskQueue queue) {
    while(queue->first == NULL) {      //while ,不是if
        pthread_cond_wait(&queue->cond, &queue->mtx); //如果是if,会导致如果队列为空，会在释放锁之前返回，导致锁未释放。使用while循环来等待条件变量并确保正确释放锁。
    }
    Task task = queue->first;
    queue->first = queue->first->next;
    if(queue->first == NULL) {
        queue->last = NULL;
    }
    return task;
}

void my_func1(void *arg) {
    int *arg1 = (int *)arg;
    printf("my_func1's arg is: %d\n", *arg1);
}

void my_func2(void *arg) {
    int *arg2 = (int *)arg;
    printf("my_func2's arg is :%d, Asynchronous processing success\n", *arg2);
}

void *thread1_fun(void *task_queue) {
    TaskQueue queue = (TaskQueue)task_queue;
    while(1) {
        pthread_mutex_lock(&queue->mtx);
        Task task = dequeue(queue);
        if(task == NULL) {
            pthread_mutex_unlock(&queue->mtx);
            continue;
        }
        pthread_mutex_unlock(&queue->mtx);

        sleep(1.5);  //模拟阻塞
        task->func(task->arg);
        free(task);
    }
    pthread_exit(NULL);
    return NULL;
}

void *thread2_fun(void *task_queue) {
    TaskQueue queue  = (TaskQueue)task_queue;
    while(1) {
        pthread_mutex_lock(&queue->mtx);
        Task task = dequeue(queue);
        if(task == NULL) {
            pthread_mutex_unlock(&queue->mtx);
            continue;
        }
        pthread_mutex_unlock(&queue->mtx);

        task->func(task->arg);
        free(task);        
    }
    return NULL;
}

pthread_t init_thread1(void *queue) {
    pthread_t thread1;
    pthread_create(&thread1, NULL, thread1_fun, (void *)queue);
    return thread1;
}
pthread_t init_thread2(void *queue) {
    pthread_t thread2;
    pthread_create(&thread2, NULL, thread2_fun, (void *)queue);
    return thread2;
}

void destroy_queue_and_thread(TaskQueue queue, pthread_t thread1, pthread_t thread2) {
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    free(queue);
}

int main() {
    //两个线程，一个主线程，当主线程阻塞，副线程负责异步处理
    
    TaskQueue queue = init_queue();
    int arg1 = 1;
    int arg2 = 2;
    enqueue(queue, my_func1, &arg1);
    enqueue(queue, my_func1, &arg2);

    pthread_t thread1 = init_thread1((void *)queue);
    pthread_t thread2 = init_thread2((void *)queue);

    sleep(2);
    destroy_queue_and_thread(queue, thread1, thread2);

    return 0;
}