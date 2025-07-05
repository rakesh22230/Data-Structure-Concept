#ifndef MYQUE_H
#define MYQUE_H

#include <iostream>
using namespace std;

template <typename N> class Node {
public:
    N value;
    Node* Next;
    Node(N val) {
        value = val;
        Next = NULL;
    }
};

template <typename Q>  class Queue {
    Node <Q> *front;
    Node <Q> *rear;
public:
    Queue() {
        front = NULL;
        rear = NULL;
    }

    void push(Q val) {
        Node <Q>  *NewNode = new Node <Q> (val);
        if (front == NULL) {
            front = NewNode;
            rear = NewNode;
            return;
        }
        rear->Next = NewNode;
        rear = rear->Next;
    }

    Q pop() {
        Q chk ;
        if (front == NULL) {
            cout << "Queue is Underflow!" << endl;
            return chk;
        }

        Node <Q> *delNode = front;
        front = front->Next;
        if (front == NULL) {
            rear = NULL;
        }

        chk = delNode->value;
        delete delNode;
        return chk;
    }

    Q Front() {
        Q chk;
        if (front == NULL) {
            cout << "Queue is Empty!" << endl;
            return chk;
        }
        chk=  front->value;
        return chk;
    }

    Q Back() {
        Q chk ;
        if (rear == NULL) {
            cout << "Queue is Empty!" << endl;
            return chk;
        }
        chk =  rear->value;
        return chk;
    }

    bool empty() {
        return (front == NULL);
    }
};

#endif

