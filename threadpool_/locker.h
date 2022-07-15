#pragma  once
#include <exception>
#include <pthread.h>
#include <semaphore.h>

using namespace std;

//线程同步机制封装
//互斥锁类

class locker{

public:
    locker();
    ~locker();
    bool lock();
    bool unlock();
    pthread_mutex_t *get();
private:
    pthread_mutex_t m_mutex;
};
class cond{
public:
    cond();
    ~cond();
    bool wait(pthread_mutex_t * m_mutex);
    bool timewait(pthread_mutex_t *m_mutex,struct timespec t);
    bool sigal();
    bool broadcast();
private:
    pthread_cond_t m_cond;
};
//信号类
class sem{
public:
    sem();
    ~sem();
    bool wait();
    bool post();
    private:
sem_t m_sem;
};