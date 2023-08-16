#ifndef MY_MSG_QUEUE_H
#define MY_MSG_QUEUE_H

template<typename T, int N>
class MyMsgQueue {
    T data[N];
    int front;
    int end;
    
};


#endif  // MY_MSG_QUEUE_H
