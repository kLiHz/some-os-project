#ifndef MY_SEMAPHORE_H
#define MY_SEMAPHORE_H

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

class MySemaphore
{
private:
    sem_t s;
    int permits;

public:
    MySemaphore(int initial) : permits(initial) {
        // assume semaphore is accessed by the threads in a single process
        int status = sem_init(&s, 0, initial);
    }
    void P() {
        int status = sem_wait(&s);
    }
    void V() {
        int status = sem_post(&s);
    }
    ~MySemaphore() {
        int status = sem_destroy(&s);
    }
};

#endif // MY_SEMAPHORE_H
