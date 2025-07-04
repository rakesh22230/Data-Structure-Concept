#ifndef MYSTACK_H
#define MYSTACK_H

#include <bits/stdc++.h>
using namespace std;

// Node class
template <typename N>
class Node {
public:
    N value;
    Node *prev;
    Node *next;

    Node(N val) {
        value = val;
        prev = NULL;
        next = NULL;
    }
};

// Stack class
template <typename S>
class Stack {
    Node<S> *head;
    Node<S> *top;
    int count = 0;

public:
    Stack() {
        head = NULL;
        top = NULL;
    }

    void push(S val) {
        Node<S> *newNode = new Node<S>(val);
        if (head == NULL) {
            head = top = newNode;
        } else {
            top->next = newNode;
            newNode->prev = top;
            top = newNode;
        }
        count++;
    }

    S pop() {
        if (head == NULL) {
            cout << "Stack is Empty!" << endl;
            exit(1); // To avoid undefined behavior
        }

        Node<S> *delNode = top;
        S chk = delNode->value;

        if (head == top) {
            head = top = NULL;
        } else {
            top = delNode->prev;
            top->next = NULL;
        }

        delete delNode;
        count--;
        return chk;
    }

    bool empty() {
        return head == NULL;
    }

    S Top() {
        if (head == NULL) {
            cout << "Stack is Empty | No element in this list" << endl;
            exit(1);
        }
        return top->value;
    }

    int size() {
        return count;
    }
};

#endif // MYSTACK_H
