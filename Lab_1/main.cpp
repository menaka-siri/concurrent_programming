#include <iostream>
#include <stdlib.h>
using namespace std;

class Node{
private:
    int value = -1;
    Node *next = NULL;

public:
    int getValue(){ return  value;}
    Node* getNext(){ return  next;}

    void setValue(int number){
        value = number;
    }

    void setNext(Node *nextNode){
        next = nextNode;
    }

};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList(){ //the constructor method
        head = NULL;
        tail = NULL;
    }

    bool member(int number){
        Node* temp = head;

        while(temp->getNext() != NULL){
            if(temp->getValue() == number){
                cout << "Current Node value [True]"<< temp->getValue()<< endl;
                return true;
            }else{
                cout << "Current Node value "<< temp->getValue()<< endl;
                temp = temp->getNext();
            }
        }
        if (temp->getNext() == NULL) {
            if(temp->getValue() == number){
                cout << "Current Node value [True]"<< temp->getValue()<< endl;
                return true;
            }
        }

        /* log prints for debugging - starts*/
        cout << "Current Head value [Not True]"<< head->getValue()<< endl;
        cout << "Current Node value [Not True]"<< temp->getValue()<< endl;
        cout << "Current Tail value [Not True]"<< tail->getValue()<< endl;
        /* log prints for debugging - ends*/

        return false;

    };

    //adding the new node at the end of the linkedlist
    void insert(int number){

        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->setValue(number);
        newNode->setNext(NULL);


        if (head == NULL) {
            tail=newNode;
            head = newNode;
        }
        else{
            tail->setNext(newNode);
            tail = newNode;
        }

    };

    bool remove(int number){

    };

};

int main() {
    //std::cout << "Hello, World!" << std::endl;
    cout << "Hello, World!" << endl;
    LinkedList newList;
    newList.insert(10);
    newList.insert(20);
    newList.insert(30);
//    newList.insert(40);

    cout << "Final: "<< newList.member(10) << endl;
//    cout << true << endl;


    return 0;

}