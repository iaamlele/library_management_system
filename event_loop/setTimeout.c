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

void *thread_func(void *args) {
    TimeoutArgs timeoutArgs = (TimeoutArgs)args;
    timeoutArgs->fun(timeoutArgs->arg);
    free(timeoutArgs);
    return NULL;
}

void setTimeout(func_ptr fun, int time, void *arg) {
    TimeoutArgs args = (TimeoutArgs)malloc(sizeof(struct timeout_args));
    args->fun = my_func;
    args->time = 1;
    args->arg = arg;

    pthread_t thread;
    
    pthread_create(&thread, NULL, thread_func, args);
    sleep(time); //以秒为单位
    pthread_join(thread, NULL);
}

int main() {
    int arg = 1;
    setTimeout(my_func, 1, &arg);

    return 0;
}