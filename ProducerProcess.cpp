#include "ProducerProcess.h"

// https://stackoverflow.com/questions/5514464/difference-between-pthread-and-fork-on-gnu-linux

// Threads in the same process communicate using shared memory

class ReaderThread : public MyThread {
// read from file by lines:
//   create a buffer (by malloc)
//   write the line into the buffer
//   push this buffer into queue1
};

class ReplaceThread : public MyThread {
// get from queue1
// process
// push to queue2
};

class ToUpperThread : public MyThread {
// get from queue2
// process
// push to queue3
};

class WriterThread : public MyThread {
// read from queue3
// write
// release the buffer
};

class Producer {
    void operator()() {

    }
};

int main() {
    
}
