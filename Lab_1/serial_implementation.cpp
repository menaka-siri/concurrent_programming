#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctime>
#include <ratio>
#include <random>
#include <chrono>
#include "LinkedList.h"
#include "support_functions.h"


using namespace std;
using  namespace std::chrono;

int main( int argc, char *argv[]) {
    cout << "Concurrent, Lab 1" << endl;
    LinkedList newList;

    cout << "Actual Simualtion" << endl;

    int program_iterations = 25;
    int n = 1000; //number of unique values to populate the linked list
    int m = 1000; //number of random operations of member, insert and delete


    float p_member = 0.40;  //fraction of 'member' operations on the linkedList
    float p_insert = 0.30;  //fraction of 'insert' operations on the linkedList
    float p_delete = 0.30;  //fraction of 'delete' operations on the linkedList

    bool user_input_flag = true; //set true to use hard coded values or else set false to take user defined values

    double total_time = 0;
    vector<double> executionTimeVector;


    int rand_num;
    int min = 1;
    int max = pow(2,16.0f) - 1;

    while (user_input_flag) {

        if( argc < 7 ){
            cout<< " There should be six parameters to start the program"<<endl;
            user_input_flag = true;
        }

        program_iterations = (int) atol(argv[1]);//number of operations

        n = (int) atol(argv[2]); //number of unique values to populate the linked list
        m = (int) atol(argv[3]); //number of random operations of member, insert and delete


        p_member = (float) atof(argv[4]);	//fraction of 'member' operations on the linkedList
        p_insert = (float) atof(argv[5]);	//fraction of 'insert' operations on the linkedList
        p_delete = (float) atof(argv[6]);	//fraction of 'delete' operations on the linkedList

        user_input_flag = false;

    }

    // initialize random seed: */
    srand ((unsigned)time(0));


    //initializing the linked list
    for(int i=0; i < n; i++){
        rand_num =  rand() % (max - min +1) + min;
        newList.insert(rand_num);
    }

    int newArraySize;
    //int task_order_array[100];
    int *task_order_array = (int *)malloc(sizeof(int));


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


        //calling the linkedList operations according to the task_order array

        steady_clock::time_point start_time = steady_clock::now();

        for (int i = 0; i < m; i++) {
            rand_num = rand() % (max - min + 1) + min;
            cout << "Operation #" << i << ": ";
            switch (task_order_array[i]) {
                case 0: {
                    cout << "member(" << rand_num << ")\t";

                    if (newList.member(rand_num)) {
                        cout << "success\n";
                    } else {
                        cout << "fail\n";
                    }

                }
                    break;

                case 1: {
                    cout << "insert(" << rand_num << ")\t";

                    if (newList.insert(rand_num)) {
                        cout << "success\n";
                    } else {
                        cout << "fail\n";
                    }
                }
                    break;

                case 2: {
                    cout << "delete(" << rand_num << ")\t";

                    if (newList.remove(rand_num)) {
                        cout << "success\n";
                    } else {
                        cout << "fail\n";
                    }
                }
                    break;
            }
        }

        steady_clock::time_point end_time = steady_clock::now();
        duration<double> time_span = duration_cast<duration<double>>(end_time - start_time);
        cout << "Time elapsed for iteration #"<<i<<": " << time_span.count() << "s" << endl;

        executionTimeVector.push_back(time_span.count());

    }

    StatisticCalc scal;
    double executionTimeArray[program_iterations];
    copy(executionTimeVector.begin(), executionTimeVector.end(), executionTimeArray);

    scal.setValues(executionTimeArray, program_iterations);

    cout<< "\n\n";
    cout << "Program iterations:\t" << program_iterations << endl;
    cout << "Initial values:\t\t" << n << endl;
    cout << "Number of operations:\t" << m << endl;
    cout << "Total time elapsed:\t" << scal.calculateSum() << "s" << endl;
    cout << "Average:\t\t" << scal.calculateMean() << "s" << endl;
    cout << "Standard Deviation:\t" << scal.getStandardDeviation() << "s" << endl;

    return 0;

}
