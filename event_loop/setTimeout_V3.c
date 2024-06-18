#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>


typedef void (*func_ptr)(void *);

typedef struct task {
    func_ptr func;
    void *arg;
    struct task *next;
} *Task;

typedef struct settimeout_task {
    time_t time;
    int begin_time;
    func_ptr func;
    void *arg;
    struct settimeout_task *last;
    struct settimeout_task *next;
} *SetTimeout_Task;

typedef struct settimeout_list {
    struct settimeout_task *head;
    struct settimeout_task *tail;
    int length;
    pthread_mutex_t mtx;
    pthread_cond_t cond;
} *SetTimeout_List;

typedef struct queue {
    struct task *first;
    struct task *last;
    pthread_mutex_t mtx;
    pthread_cond_t cond;
} *TaskQueue;

SetTimeout_List create_list() {
    SetTimeout_List my_list = (SetTimeout_List)malloc(sizeof(struct settimeout_list));
    my_list->head = my_list->tail = NULL;
    my_list->length = 0;
    return my_list;
}

void push_list(SetTimeout_List list, SetTimeout_Task task) {
    if(list->length == 0) {
        list->head = list->tail = task;
    }else {
        list->tail->next = task;
        task->last = list->tail;
        list->tail = task;
    }
    list->length++;
}


SetTimeout_Task setTimeout_list_check(SetTimeout_List list) {
    pthread_mutex_lock(&list->mtx);
    SetTimeout_Task task = list->head;
    while(task != NULL) {
        if(list->head == NULL) {
            continue;
        }
        time_t current_time = time(NULL);
        if(current_time - task->begin_time >= task->time) {
            // remove task
            if(task == list->head) {
                list->head = list->head->next;
            }else {
                task->last->next = task->next;
                task->next->last = task->last;
            }

            if(task == list->tail) {
                list->tail = task->last;
            }
            list->length--;
            pthread_mutex_unlock(&list->mtx);                
            return task; //后面会free，所以这里不需要
        }else {
            task = task->next;
        }    
        pthread_mutex_unlock(&list->mtx);
        return NULL;
    }

}

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

void *thread1_fun(void *task_queue) { //主线程，循环执行队列中任务
    TaskQueue queue = (TaskQueue)task_queue;
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
    pthread_exit(NULL);
    return NULL;
}

void *thread2_fun(void *args) {
    SetTimeout_List list = (SetTimeout_List)((void **)args)[0];
    TaskQueue queue  = (TaskQueue)((void **)args)[1];
    free(args);

    while(1) {
        SetTimeout_Task task = setTimeout_list_check(list);
        if(task != NULL) {
            enqueue(queue, task->func, task->arg);
            free(task);
        }else {
            continue;
        }
    }
    
    pthread_exit(NULL);
    return NULL; 
}

pthread_t init_thread1(void *queue) {
    pthread_t thread1;
    pthread_create(&thread1, NULL, thread1_fun, (void *)queue);
    return thread1;
}
pthread_t init_thread2(SetTimeout_List list, TaskQueue queue) {
    pthread_t thread2;
    void **args = (void **) malloc(sizeof(void *) * 2);
    args[0] = list;
    args[1] = queue;

    pthread_create(&thread2, NULL, thread2_fun, args);
    return thread2;
}

void destroy_queue_thread_and_list(TaskQueue queue, pthread_t thread1, pthread_t thread2, SetTimeout_List list) {
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    free(queue);

    if(list->length != 0) {
        SetTimeout_Task current = list->head;
        while(current->next != NULL) {
            SetTimeout_Task next = current->next;
            free(current);
            current = next;
        }
    }
    free(list);
}

void setTimeout(time_t delay_time, func_ptr func, void *arg, SetTimeout_List list) {

    SetTimeout_Task task = (SetTimeout_Task)malloc(sizeof(struct settimeout_task));
    task->func = func;
    task->arg = arg;
    task->last = task->next = NULL;

    time_t begin_time = time(NULL);
    task->begin_time = begin_time;
    task->time = delay_time;

    if(task == NULL) {
        return;
    }

    if(list == NULL) {
        free(task);
        return;
    }
    push_list(list, task);
}

void init_model() {
    
}

int main() {
    TaskQueue queue = init_queue();
    SetTimeout_List list = create_list();

    int arg1 = 1;
    int arg2 = 2;
    enqueue(queue, my_func1, &arg1);
    enqueue(queue, my_func1, &arg2);

    int arg3 = 3;
    setTimeout(2, my_func2, &arg3, list);

    pthread_t thread1 = init_thread1((void *)queue);
    pthread_t thread2 = init_thread2(list, queue);

    sleep(4);
    destroy_queue_thread_and_list(queue, thread1, thread2, list);

    return 0;
}