#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

//setTimeout(func, time)
typedef void (*func_ptr)(void *);

void my_func(void *arg) {
    int *my_func_arg = (int *)arg;
    printf("my_func arg is:%d\n", *my_func_arg);
}

void setTimeout(func_ptr fun, int time, void *arg) {
    sleep(time); //以秒为单位
    (*fun)(arg);
}
int main() {
    int arg = 1;
    pthread_t thread1;
    pthread_create(&thread1, NULL , setTimeout, (my_func, 1000, &arg));
    printf("OK\n");
    pthread_join(thread1, NULL);
    

    return 0;
}