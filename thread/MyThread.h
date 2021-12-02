#ifndef MY_THREAD_H
#define MY_THREAD_H

#include <pthread.h>

inline static void *runThread(void *arg);

class MyThread
{
private:
    pthread_t m_tid; // contains the thread ID
    int m_running;
    int m_detached;

public:
    MyThread() : m_tid(0), m_running(0), m_detached(0) {}

    pthread_t self() { return m_tid; }

    virtual void *run() = 0;

    int start()
    {
        int result = pthread_create(&m_tid, NULL, runThread, this);
        if (result == 0)
        {
            m_running = 1;
        }
        return result;
    }

    int join()
    {
        int result = -1;
        if (m_running == 1)
        {
            result = pthread_join(m_tid, NULL);
            if (result == 0)
            {
                m_detached = 1; // pthread_join() automatically detatches a thread
            }
        }
        return result;
    }

    int detached()
    {
        int result = -1;
        if (m_running == 1 && m_detached == 0)
        {
            result = pthread_detach(m_tid);
            if (result == 0)
            {
                m_detached = 1;
            }
        }
        return result;
    }

    virtual ~MyThread()
    {
        if (m_running == 1 && m_detached == 0)
        {
            pthread_detach(m_tid);
        }
        if (m_running == 1)
        {
            pthread_cancel(m_tid);
        }
    }
};

inline static void *runThread(void *arg)
{
    return ((MyThread *)arg)->run();
}

#endif  // MY_THREAD_H
