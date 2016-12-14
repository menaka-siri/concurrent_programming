#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "LinkedList.h"

#define  TEST true

using namespace std;

int main() {
    cout << "Concurrent, Lab 1" << endl;
    LinkedList newList;

    //basic simulation
    if (false) {
        newList.insert(10);
        newList.insert(20);
        newList.insert(30);
        newList.insert(40);

        cout << "Member: "<< newList.member(10) << endl;
        cout << "Remove: "<< newList.remove(50) << endl;
        cout << "Member: "<< newList.member(45) << endl;
    }

#if TEST

    cout << "Actual Simualtion" << endl;

    int n = 100; //number of unique values to populate the linked list
    int m = 100; //number of random operations of member, insert and delete
    int m_member;
    int m_insert;
    int m_delete;

    int rand_num;
    int min = 1;
    int max = pow(2,16) -1;

    // initialize random seed: */
//    srand ((unsigned)time(0));
    srand (1);

    //initializing the linked list
    for(int i=0; i < n; i++){
        rand_num =  rand() % (max - min +1) + min;
        newList.insert(rand_num);
    }

    newList.print();

#endif

    return 0;

}
