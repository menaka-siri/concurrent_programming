#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctime>
#include <ratio>
#include <random>
#include <chrono>
#include <pthread.h>
#include "LinkedList.h"
#include "support_functions.h"
#include "MyThreadClass.h"

//global variables
LinkedList newList;

int m = 1000; //number of random operations of member, insert and delete

pthread_mutex_t listlock_mutex;// one mutex for the entire list
int thread_count;

int newArraySize;
int *task_order_array;

MyThreadClass myThreadClassArray;
std::vector<MyThreadClass*> myhtreads(10);

void* ThreadEntryFunc(void *rank);

using namespace std;
using  namespace std::chrono;

int main( int argc, char *argv[]) {
    cout << "Concurrent, Lab 1" << endl;
    cout << "Actual Simualtion --- Mutex Implementation " << endl;

    int program_iterations = 2;
    int n = 100; //number of unique values to populate the linked list
    m = 100; //number of random operations of member, insert and delete

    thread_count = 4;

    float p_member = 0.40;  //fraction of 'member' operations on the linkedList
    float p_insert = 0.30;  //fraction of 'insert' operations on the linkedList
    float p_delete = 0.30;  //fraction of 'delete' operations on the linkedList

    bool user_input_flag = true; //set true to use hard coded values or else set false to take user defined values

    vector<double> executionTimeVector;

    int rand_num;
    int min = 1;
    int max = pow(2,16.0f) - 1;

    while (user_input_flag) {

        if( argc < 8 ){
            cout<< " There should be seven parameters to start the program"<<endl;
            user_input_flag = true;
        }

        program_iterations = (int) atol(argv[1]);//number of operations

        thread_count  = (int) atol(argv[2]);//number of threads

        n = (int) atol(argv[3]); //number of unique values to populate the linked list
        m = (int) atol(argv[4]); //number of random operations of member, insert and delete


        p_member = (float) atof(argv[5]);	//fraction of 'member' operations on the linkedList
        p_insert = (float) atof(argv[6]);	//fraction of 'insert' operations on the linkedList
        p_delete = (float) atof(argv[7]);	//fraction of 'delete' operations on the linkedList

        user_input_flag = false;

    }

    // initialize random seed: */
    srand ((unsigned)time(0));


    //tempList = *newList;

    //initializing the linked list
    for(int i=0; i < n; i++){
        rand_num =  rand() % (max - min +1) + min;
        newList.insert(rand_num);
    }

    //int task_order_array[100];
    task_order_array = (int *)malloc(sizeof(int));


    //performing the test operations
    for(int i = 0; i < program_iterations ; i++) {
        cout << "\n\n--- Iteration #: "<< i << endl;

        task_order_array = getTaskOrderArray(m, p_member, p_insert, p_delete);
        newArraySize = getTaskOrderArraySize();

        cout << "\n\n--- From the getTaskOrderArray method: " << endl;

        if (false) { //set true to check the output
            if (newArraySize != -1) {
                for (int i = 0; i < newArraySize; i++) {
                    //cout << "element "<<i<<": " <<*(task_order_array+i) <<endl;
                    cout << "element " << i << ": " << task_order_array[i] << endl;
                }
            } else {
                cout << "Error: task_order array was not initialized correctly!" << endl;
            }
        }

        std::vector<MyThreadClass> mythreads(thread_count);
        steady_clock::time_point start_time = steady_clock::now();

        //calling the linkedList operations according to the task_order array --- starts

        pthread_mutex_init(&listlock_mutex, NULL);
        for (int thread = 0; thread < thread_count; thread++)
        {
            mythreads[thread].Init( (void*)thread);
        }

        for (int thread = 0; thread < thread_count; thread++)
        {
            mythreads[thread].WaitForThreadToExit();

        }

        pthread_mutex_destroy(&listlock_mutex);

        //calling the linkedList operations according to the task_order array --- ends

        steady_clock::time_point end_time = steady_clock::now();
        duration<double> time_span = duration_cast<duration<double>>(end_time - start_time);
        cout << "\nTime elapsed for iteration #"<<i<<": " << time_span.count() << "s" << endl;

        executionTimeVector.push_back(time_span.count());

    }

    StatisticCalc scal;
    double executionTimeArray[program_iterations];
    copy(executionTimeVector.begin(), executionTimeVector.end(), executionTimeArray);

    scal.setValues(executionTimeArray, program_iterations);

    cout<< "\n\n";
    cout << "Program iterations:\t" << program_iterations << endl;
    cout << "Thread count:\t\t" << thread_count << endl;
    cout << "Initial values:\t\t" << n << endl;
    cout << "Number of operations:\t" << m << endl;
    cout << "Total time elapsed:\t" << scal.calculateSum() << "s" << endl;
    cout << "Average:\t\t" << scal.calculateMean() << "s" << endl;
    cout << "Standard Deviation:\t" << scal.getStandardDeviation() << "s" << endl;

    return 0;

}

void* ThreadEntryFunc(void *rank) {
    MyThreadClass *thr  = ((MyThreadClass *)rank);

    int my_rank = (int)rank;
    int start_pos = (m/thread_count)*my_rank;		//start position of the task_order_array
    int end_pos = (m/thread_count)*(my_rank+1);		//end position of the task_order_array

    if((my_rank+1)==thread_count){					//if  it is the last thread, end position will be  'm'
        end_pos=m;
    }

    srand(time(NULL));
    int thread_rand_num;
    int min = 1;
    int max = pow(2,16.0f) - 1;

    for (int i=start_pos ; i< end_pos ; i++) {

        thread_rand_num = rand() % (max - min + 1) + min;

        switch (task_order_array[i]) {

            case 0: {
                pthread_mutex_lock(&listlock_mutex);
                cout << "Operation #"<< i << " \t";
                cout << "Thread #"<< my_rank <<"  member(" << thread_rand_num << ")    \t";
                if (newList.member(thread_rand_num)) {
                    cout << "success\n";
                } else {
                    cout << "fail\n";
                }
                pthread_mutex_unlock(&listlock_mutex);
            }
                break;

            case 1: {
                pthread_mutex_lock(&listlock_mutex);
                cout << "Operation #"<< i << " \t";
                cout << "Thread #"<< my_rank << "  insert(" << thread_rand_num <<")    \t";
                if (newList.insert(thread_rand_num)) {
                    cout << "success\n";
                } else {
                    cout << "fail\n";
                }
                pthread_mutex_unlock(&listlock_mutex);
            }
                break;

            case 2: {
                pthread_mutex_lock(&listlock_mutex);
                cout << "Operation #"<< i << " \t";
                cout << "Thread #"<< my_rank << "  delete(" << thread_rand_num << ")    \t";
                if (newList.remove(thread_rand_num)) {
                    cout << "success\n";
                } else {
                    cout << "fail\n";
                }
                pthread_mutex_unlock(&listlock_mutex);
            }
                break;
        }
    }

    return NULL;
}


