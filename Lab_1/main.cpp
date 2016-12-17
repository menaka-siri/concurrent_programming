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

#define  TEST true
//#define  TEST false

using namespace std;
using  namespace std::chrono;

int main() {
    cout << "Concurrent, Lab 1" << endl;
    LinkedList newList;

    //basic simulation
    if (false) {
        newList.insert(10);
        newList.insert(20);
        newList.insert(30);
        newList.insert(40);
        newList.insert(10);

        cout << "Member: "<< newList.member(10) << endl;
        cout << "Remove: "<< newList.remove(50) << endl;
        cout << "Member: "<< newList.member(45) << endl;
    }

#if TEST

    cout << "Actual Simualtion" << endl;

    int n = 100000; //number of unique values to populate the linked list
    int m = 100; //number of random operations of member, insert and delete

    pthread_mutex_t  list_mutex;

    float p_member = 0.40;
    float p_insert = 0.30;
    float p_delete = 0.30;
    bool user_input_flag = true; //set true to use hard coded values or else set false to take user defined values

//    auto start_time;
//    auto end_time ;
    double total_time = 0;
    vector<double> executionTimeVector;


    int rand_num;
    int min = 1;
    int max = pow(2,16.0f) - 1;

    //assigning the user inputs to main variables --- starts

    while (!user_input_flag) {
        cout<< "Total number of unique values: ";
        cin >> n;

        cout<< "Total number of operations: ";
        cin >> m;

        cout<< "Probability of 'member' operation: ";
        cin >> p_member;

        cout<< "Probability of 'insert' operation: ";
        cin >> p_insert;

        cout<< "Probability of 'delete' operation: ";
        cin >> p_delete;

        if(  (int)(p_member+ p_insert+ p_delete) == 1){
            user_input_flag = true;
        }else{
            cout<<"Total probability: " << p_member+ p_insert+ p_delete <<endl;
            cout << "Incorrect probability values, please insert the probability values again!\n";
        }
    }

    //assigning the user inputs to main variables --- starts



    // initialize random seed: */
    //srand (1);
    srand ((unsigned)time(0));


    //initializing the linked list
    for(int i=0; i < n; i++){
        rand_num =  rand() % (max - min +1) + min;
        newList.insert(rand_num);
    }

//    newList.print();

//    newList = LinkedList();
//    for(int i=0; i < n; i++){
//        rand_num =  rand() % (max - min +1) + min;
//        newList.insert(rand_num);
//    }
//
//    newList.print();

    int newArraySize;
//    int task_order_array[100];
    int *task_order_array = (int *)malloc(sizeof(int));


    //performing the test operations
//    for(int i = 0; i<m; i++) {
    if(true){ // this if block is for the easy control of the program

        task_order_array = getTaskOrderArray(m, p_member, p_insert, p_delete);

        cout << "\n\n--- From the getTaskOrderArray method: "<<endl;

        newArraySize = getTaskOrderArraySize();


        if (newArraySize != -1) {
            for(int i=0; i < newArraySize ; i++){
//                cout << "element "<<i<<": " <<*(task_order_array+i) <<endl;
                cout << "element "<<i<<": " << task_order_array[i] <<endl;
            }
        }else{
            cout <<"Error: task_order array was not initialized correctly!"<<endl;
        }

        //defining the probability of each function  --- ends

        //calling the linkedList operations according to the task_order array
        steady_clock::time_point start_time = steady_clock::now();
        for (int i=0; i < m ; i++) {
            rand_num =  rand() % (max - min +1) + min;
            cout<<"Iteration #"<<i<<": ";
            switch(task_order_array[i]) {
                case 0: {
                    cout << "member(" << rand_num << ")\t";

                    steady_clock::time_point start_time = steady_clock::now();
                    if (newList.member(rand_num)) {
                        cout << "success\t";
                    } else {
                        cout << "fail\t";
                    }
                    steady_clock::time_point end_time = steady_clock::now();

                    //total_time += (end_time - start_time) / std::chrono::milliseconds(1);
                    duration<double> time_span = duration_cast<duration<double>>(end_time - start_time);
                    double elapsedSeconds = ((end_time - start_time).count()) * steady_clock::period::num / static_cast<double>(steady_clock::period::den);
                    //cout << time_span.count() << "ms" << endl;
                    cout << elapsedSeconds *1000 << "ms" << endl;

                    total_time += time_span.count();

                    //cout << (start_time - end_time) / std::chrono::milliseconds(1) << "ms" << endl;
                }
                    break;

                case 1: {
                    cout << "insert(" << rand_num << ")\t";

                    steady_clock::time_point start_time = steady_clock::now();
                    if (newList.insert(rand_num)) {
                        cout << "success\t";
                    } else {
                        cout << "fail\t";
                    }
                    steady_clock::time_point end_time = steady_clock::now();
                    duration<double> time_span = duration_cast<duration<double>>(end_time - start_time);
                    cout << time_span.count() << "ms" << endl;

                    total_time += time_span.count();
                }
                    break;

                case 2:{
                    cout<<"delete("<<rand_num<<")\t";

                    steady_clock::time_point start_time = steady_clock::now();
//                    if (newList.remove(rand_num)) {
//                        cout << "success\t";
//                    } else {
//                        cout << "fail\t";
//                    }
                    newList.remove(rand_num);
                    steady_clock::time_point end_time = steady_clock::now();
                    duration<double> time_span = duration_cast<duration<double>>(end_time - start_time);
                    double elapsedSeconds = ((end_time - start_time).count()) * steady_clock::period::num / static_cast<double>(steady_clock::period::den);
                    cout << time_span.count() << "s" << endl;
                    //cout << elapsedSeconds << "s" << endl;

                    total_time += time_span.count();
                }
                    break;
            }
        }
        steady_clock::time_point end_time = steady_clock::now();
        duration<double> time_span = duration_cast<duration<double>>(end_time - start_time);
        double elapsedSeconds = ((end_time - start_time).count()) * steady_clock::period::num / static_cast<double>(steady_clock::period::den);
        //cout << time_span.count() << "ms" << endl;
        cout << "Total TIme: time span: "<< time_span.count() << "s" << endl;
        cout << "Total TIme: "<< elapsedSeconds *1000 << "ms" << endl;


//        cout <<"Iteration: "<< i << endl;

    }

    //cout <<"\n\nAfter: "<< endl;
    //newList.print();

#endif

    return 0;

}
