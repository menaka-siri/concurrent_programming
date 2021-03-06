//
// Created by Siri on 12/14/2016.
// This header file includes the declaration of Node and LinkedList classes
//
#include <iostream>
#include <stdlib.h>

#ifndef LAB_1_LINKEDLIST_H
#define LAB_1_LINKEDLIST_H

using namespace std;

class Node{
private:
    int value = -1;
    Node *next ;

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
    Node* head = (Node *)malloc(sizeof(Node));
    Node* tail = (Node *)malloc(sizeof(Node));

public:
    LinkedList(){ //the constructor method
        head = NULL;
        tail = NULL;
    }

    //check whether a given element is in the linkedList
    bool member(int number){
        Node* temp = head;

        while(temp->getNext() != NULL){
            if(temp->getValue() == number){
                //cout << "Current Node value [True]"<< temp->getValue() << endl;
                return true;
            }else{
                //cout << "Current Node value "<< temp->getValue() << endl;
                temp = temp->getNext();
            }
        }
        if (temp->getNext() == NULL) {
            if(temp->getValue() == number){
                //cout << "Current Node value [True]"<< temp->getValue()<< endl;
                return true;
            }
        }

        /* log prints for debugging - starts*/
        if (false) {
            cout << "Current Head value [Not True]"<< head->getValue()<< endl;
            cout << "Current Node value [Not True]"<< temp->getValue()<< endl;
            cout << "Current Tail value [Not True]"<< tail->getValue()<< endl;
        }
        /* log prints for debugging - ends*/

//        cout << "Error[Member]: "<< number <<" element is not in the list! "<< endl;
        return false;

    };

    //adding the new node at the end of the linkedlist
    bool insert(int number){

        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->setValue(number);
        newNode->setNext(NULL);


        if (head == NULL) {
            tail=newNode;
            head = newNode;
            return true;
        }
        else{
            if (!this->member(number)) {
                tail->setNext(newNode);
                tail = newNode;
                return true;
            }else{
                //cout << number <<" is already in the list!"<<endl;
                return false;
            }
        }

    };

    //removing a given element from the list
    bool remove(int number){
        Node *tempNode = (Node *)malloc(sizeof(Node));

        Node* temp = head;
        Node* prev = temp;

        while(true){
            if(temp->getNext() == NULL){
                //either linkedList is empty or reached the last element
                break;
            }
            if(temp->getValue() == number){
//                cout << "Current Node value [True]"<< temp->getValue()<< endl;
                prev->setNext(temp->getNext()); //creating a link between the prev. node and the node after the current node
                temp->setNext(NULL); //deleting the current node pointer to the next node
                return true;
            }else{
//                cout << "Current Node value "<< temp->getValue()<< endl;
                prev = temp;
                temp = temp->getNext();
            }
        }
//        cout << "Error[Remove]: "<< number <<" element is not in the list! "<< endl;
        return false;
    };

    //print the list
    void print(){
        Node* temp = head;

        cout<< "The list items: "  << endl;

        while(temp->getNext() != NULL){
            cout << temp->getValue() << "  " << flush;
            temp = temp->getNext();
        }

        if (temp->getNext() == NULL) {
            cout <<  temp->getValue() << "  " << endl;
        }
    }

};


#endif //LAB_1_LINKEDLIST_H
