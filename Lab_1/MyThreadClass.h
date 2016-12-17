//
// Created by Siri on 12/17/2016.
// Source: the solution given by Jeremy Friesner in the below thread in StackOverflow
// http://stackoverflow.com/questions/1151582/pthread-function-from-a-class
//
//Note: Please note that the original code was modified to match the context of Lab_1 in CS4532( yr.2016 - sem 8) (CSE- 12-batch)
//

#include <pthread.h>

void* ThreadEntryFunc(void *obj_param);

class MyThreadClass
{
public:
    MyThreadClass() {/* empty */}
    virtual ~MyThreadClass() {/* empty */}

    bool Init(void* currentRank)
    {
//        return (pthread_create(&_thread, NULL, &ThreadEntryFunc, this) == 0);
        rank = (int)currentRank;

        return (pthread_create(&_thread, NULL, &ThreadEntryFunc, (void*)rank) == 0);
    }

    /** Will not return until the internal thread has exited. */
    void WaitForThreadToExit()
    {
        (void) pthread_join(_thread, NULL);
    }

private:
    //friend function that runs the thread task
    friend void* ThreadEntryFunc(void *);  //defined in mutex_implementation.cpp and read_write_lock_implementation.cpp

    pthread_t _thread;

    int rank;
};
