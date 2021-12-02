#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "MyThread.h"

class PrintThread : public MyThread
{
  public:
    void *run() override {
        for (int i = 0; i < 5; i++) {
            printf("thread %lu running - %d\n",  (long unsigned int)self(), i+1);
            sleep(2);
        }
        printf("thread %lu done\n", (long unsigned int)self());
        return NULL;
    }
};

#include <vector>

int main() {
    std::vector<PrintThread*> th(5);
    for (int i = 0; i < th.size(); ++i) {
        th[i] = new PrintThread();
    }
    for (int i = 0; i < th.size(); ++i) {
        th[i]->start();
    }
    for (int i = 0; i < th.size(); ++i) {
        th[i]->join();
    }
    printf("main done\n");
    exit(0);
}
