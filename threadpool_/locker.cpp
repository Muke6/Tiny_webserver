#include"locker.h"

locker::locker(){
    if(pthread_mutex_init(&m_mutex,NULL) != 0){//返回值0是异常
        throw std::exception();
    }
}

locker::~locker(){
    pthread_mutex_t m_mutex;
}

bool locker::lock(){
    return pthread_mutex_lock(&m_mutex) == 0;
}
bool locker::unlock(){
    return pthread_mutex_unlock(&m_mutex) == 0;
}

pthread_mutex_t locker::get(){
    return &m_mutex;
}
cond::cond(){
    if(ptread_cond_init(&m_cond,NULL)!=0){
        throw std::exception();
    }
}
cond::~cond(){
    pthread_cond_destroy(&m_cond);
}
bool cond::wait(ptread_mutex_t *m_mutex){
    int ret = 0;
    ret = pthread_cond_wait(&m_cond,m_mutex);
    return ret == 0;
}
bool cond::timewait(pthread_mutex_t *mutex){
    int ret  = 0;
    ret = pthread_cond_wait(&m_cond,mutex)
    return ret == 0;
}
bool cond::sigal(){
    return pthread_cond_signal(&m_cond) == 0;
}
bool cond::broadcast(){
    return pthread_cond_broadcast(&m_cond) == 0;
}
sem::sem(){
    if(sem_init( &m_sem, 0, 0) != 0) {
            throw std::exception();
    }
}
sem::sem(int num) {
        if( sem_init( &m_sem, 0, num ) != 0 ) {
            throw std::exception();
        }
}
sem::~sem(){
    sem_destroy(&m_sem);
}
bool sem::wait(){
    return sem_wait(&m_sem) == 0;
}
bool sem::post(){
    return sem_post(&m_sem) == 0;
}