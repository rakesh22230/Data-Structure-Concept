#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
		int value;
		Node* Next;
	Node(int val){
		value = val;
		Next = NULL;
	}
};
void insertAtHead(Node* &head,int val);
void insertAtTail(Node* &head,int val);
void insertAtSpecificPostion(Node* &head,int position,int val);
void display(Node* n);
int countLength(Node* &head);

// Insert At Head 
void insertAtHead(Node* &head,int val){
	Node* newNode = new Node(val);
	newNode->Next = head;
	//update the head
	head = newNode;
}
// Insert At Tail
void insertAtTail(Node* &head,int val){
	Node* newNode = new Node(val);
	if(head==NULL){
		head = newNode;
		return;
	}
	Node* temp = head;
	while(temp->Next != NULL){
		temp = temp->Next;
	}
	temp->Next = newNode;
}
// Insertion at specific Postion
void insertAtSpecificPostion(Node* &head,int position,int val){
	Node* temp = head;
	int i = 0;
	while(i<position-2){
		temp = temp->Next;
		i++;
	}
	Node* newNode = new Node(val);
	newNode->Next = temp->Next;
	temp->Next = newNode;
}
// Show display
void display(Node* n){
	while(n!= NULL){
		cout<<n->value;
		if(n->Next != NULL) cout<<"->";
	  n = n->Next;
	}
	cout<<endl;
}
// Count of length
int countLength(Node* &head){
	int count = 0;
	Node* temp = head;
	while(temp !=NULL){
		count++;
		temp = temp->Next;
	}
	return count;
}
// Main function
int main(){
	Node* head = NULL;
	int value;
	cout << "Choice 1: Insertion at Head" << endl
	     << "Choice 2: Insertion at Tail" << endl
	     << "Choice 3: Insertion at Specific Postion"<<endl
	     << "Choice 0: Exit" << endl;

	int choice,position;
	cout  << "Next Choice: ";
	cin >> choice;

	while(choice != 0){
		
		switch(choice){
			case 1:
				cout<<"Enter the value: ";
				cin>>value;
				insertAtHead(head,value);
				break;
			case 2:
				cout<<"Enter the value: ";
				cin>>value;
				insertAtTail(head,value);
				break;
			case 3:
				cout<<"Enter the desired position: ";
				cin>>position;
				cout<<"Enter the value: ";
				cin>>value;
				insertAtSpecificPostion(head,position,value);
				break;
			default:
				cout<<"Invalid Choice";
		}

		cout << "Next Choice: ";
		cin >> choice;
	}

	cout << endl << "Final Linked List: ";
	display(head);
	cout<<"Length of List: "<<countLength(head)<<endl;
		
  return 0;	
}
