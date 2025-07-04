// MYSTACK.h
#ifndef MYSTACK_H
#define MYSTACK_H

#include <bits/stdc++.h>
using namespace std;

// Create class Node
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

// Create Class for Stack
template<typename S>
class Stack {
    Node<S> *head;
    Node<S> *top;
    int count = 0;

public:
    // Stack Constructor
    Stack() {
        head = NULL;
        top = NULL;
    }

    // PUSH Operation
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

    // POP Operation
    S pop() {
        if (head == NULL) {
            cout << "Stack is Empty!" << endl;
            exit(1); // Stop program to avoid undefined behavior
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

    // Empty Operation
    bool empty() {
        return head == NULL;
    }

    // Top Operation
    S Top() {
        if (head == NULL) {
            cout << "Stack is Empty! No element to show." << endl;
            exit(1); // Optional: handle empty case safely
        }
        return top->value;
    }

    // Size Operation
    int size() {
        return count;
    }
};

#endif // MYSTACK_H
