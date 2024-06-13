#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

//setTimeout(func, time)
typedef void (*func_ptr)(void *);
typedef struct timeout_args {
    func_ptr fun;
    int time;
    void *arg;
} *TimeoutArgs;

void my_func(void *arg) {
    int *my_func_arg = (int *)arg;
    printf("my_func arg is:%d\n", *my_func_arg);
}

void setTimeout(func_ptr fun, int time, void *arg) {
    sleep(time); //以秒为单位
    (*fun)(arg);
}

void *thread_func(void *args) {
    TimeoutArgs timeoutArgs = (TimeoutArgs)args;
    setTimeout(timeoutArgs->fun, timeoutArgs->time, timeoutArgs->arg);
    free(timeoutArgs);
    return NULL;
}

int main() {
    int arg = 1;
    pthread_t thread1;

    TimeoutArgs args = (TimeoutArgs)malloc(sizeof(struct timeout_args));
    args->fun = my_func;
    args->time = 1;
    args->arg = &arg;

    pthread_create(&thread1, NULL , thread_func, args);
    printf("OK\n");
    pthread_join(thread1, NULL);
    

    return 0;
}