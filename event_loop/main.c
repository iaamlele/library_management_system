#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef void (*task_func)(void*);

typedef struct task {
    task_func func;
    void *arg;
    struct task *next;
} *Task;

typedef struct queue {
    Task front;
    Task rear;
    pthread_mutex_t lock; //互斥锁
    pthread_cond_t cond;//条件变量
} *TaskQueue;

void init_queue(TaskQueue queue) {
    queue->front = queue->rear = NULL;
    pthread_mutex_init(&queue->lock, NULL);
    pthread_cond_init(&queue->cond, NULL);
}

void enqueue(TaskQueue queue, task_func func, void *arg) {
    Task task = (Task *)malloc(sizeof(struct task));
    task->func = func;
    task->arg = arg;
    task->next = NULL;

    pthread_mutex_lock(&queue->lock);
    if(queue->rear == NULL) {
        queue->front = queue->rear = task;
    }else {
        queue->rear->next = task;
        queue->rear = task;
    }
    pthread_cond_signal(&queue->cond);
    pthread_mutex_unlock(&queue->lock);
}

int is_empty(TaskQueue queue) {
    return (queue->front == NULL);
}

Task dequeue(TaskQueue queue) {
    pthread_mutex_lock(&queue->lock);
    while(is_empty(queue)) {
        pthread_cond_wait(&queue->cond, &queue->lock);
    }
    Task task = queue->front;
    queue->front = queue->front->next;
    if(queue->front == NULL) {
        queue->front = NULL;
    }
    pthread_mutex_unlock(&queue->lock);

    return task;
}

void event_loop(TaskQueue queue) {
    while(1) {
        Task task = dequeue(queue);

        if(task) {
            task->func(task->arg);
            free(task);
        }
    }
}


//添加异步任务
void async_task(void *arg) {
    int *num = (int*) arg;
    printf("Async Task Executed with arg: %d\n", *num);
}

void* add_async_task(void *arg) {
    TaskQueue *queue = (TaskQueue*) arg;
    int arg1 = 1;
    int arg2 = 2;

    // 模拟异步任务的处理
    enqueue(queue, async_task, &arg1); // 立即添加任务
    sleep(2); // 模拟任务延迟
    enqueue(queue, async_task, &arg2); // 延迟2秒后添加任务

    return NULL;
}


int main() {
    TaskQueue queue;
    init_queue(&queue);

    pthread_t adder_thread;
    pthread_create(&adder_thread, NULL, add_async_task, &queue);

    event_loop(&queue);

    pthread_join(adder_thread, NULL);

    return 0;
}
