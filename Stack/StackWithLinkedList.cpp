#include<bits/stdc++.h>
using namespace std;

// Create class Node
class Node{
	public:
		int value;
		Node *prev;
		Node *next;
	Node(int val){
		value = val; 
		prev = NULL;
		next = NULL;
	}
};

// Create Class for Stack
class Stack{
	Node *head;
	Node *top;
	int count = 0;

public:
	// Stack Constructor
	Stack(){
		head = NULL;
		top = NULL;
	}

	// PUSH Operation
	void push(int val){
		Node *newNode = new Node(val);
		if(head==NULL){
			head = top = newNode;
			count++;
			return;
		} else{
			top->next = newNode;
			newNode->prev = top;
			top = newNode;
			count++;
		}
	}

	// POP Operation
	int pop(){
		Node *delNode;
		delNode = top;
		int chk = -1;

		if(head==NULL){
			cout<<"Stack is Empty!"<<endl;
			return -1;
		}

		if(head==top){
			head=top=NULL;
		} else{
			top = delNode->prev;
			top->next = NULL;
		}

		chk = delNode->value;
		delete delNode;
		count--;
		return chk;
	}

	// Empty Operation
	bool empty(){
		if(head==NULL) return true;
		return false;
	}

	// Top Operation
	int Top(){
		int chk;
		if(head==NULL){
			cout<<"Stack is Empty | There is no element in this list"<<endl; // ? Corrected message
			chk = -1;
		}
		else
		  chk = top->value;
		return chk;
	}

	// Size Operation
	int size(){
		return count;
	}

};

int main() {
    Stack st;         // ? Create an object of Stack
    st.push(1);      // ? Use the object to call push()
    st.push(2);
    st.push(3);
    st.push(4);

    cout << "Top: " << st.Top() << endl;
    cout<<"Pop is : "<<st.pop()<<endl;
    cout << "Top now: " << st.Top() << endl;
    cout << "Size now: " << st.size() << endl;

    return 0;
}

