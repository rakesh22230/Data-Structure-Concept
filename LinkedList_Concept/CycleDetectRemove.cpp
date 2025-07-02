#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int value;
    Node* Next;
    Node(int val)
    {
        value = val;
        Next = NULL;
    }
};
struct Test
{
    int pos[1000];
};
void insertAtHead(Node* &head,int val);
void insertAtTail(Node* &head,int val);
void display(Node* n);
int countLength(Node* &head);
// Insert At Head
void insertAtHead(Node* &head,int val)
{
    Node* newNode = new Node(val);
    newNode->Next = head;
    //update the head
    head = newNode;
}
// Insert At Tail
void insertAtTail(Node* &head,int val)
{
    Node* newNode = new Node(val);
    if(head==NULL)
    {
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->Next != NULL)
    {
        temp = temp->Next;
    }
    temp->Next = newNode;
}

// Show display
void display(Node* n)
{
    while(n!= NULL)
    {
        cout<<n->value;
        if(n->Next != NULL) cout<<"->";
        n = n->Next;
    }
    cout<<endl;
}
// Count of length
int countLength(Node* &head)
{
    int count = 0;
    Node* temp = head;
    while(temp !=NULL)
    {
        count++;
        temp = temp->Next;
    }
    return count;
}

// Reversal Recursive Linked List :
Node *reverseRecursive(Node* &head){

	// Base Call
	if(head==NULL || head->Next==NULL){
	  if(head==NULL) cout<<"The Linked list is empty!"<<endl;
	  return head;
	}
	// Recursive Call
	Node *newHead = reverseRecursive(head->Next);
	head->Next->Next = head;
	head->Next = NULL;
	
	return newHead;
}
// Find Mid Value :
int findMid(Node* &head){
	if(head==NULL){
		return -1;
	}
	Node *slow = head;
	Node *fast = head;
	while(fast!=NULL && fast->Next!=NULL){
		slow = slow->Next;
		fast = fast->Next->Next;
	}
	return slow->value;
}
// Make Cycle :
void makeCycle(Node* &head,int position){
	Node *temp = head;
	Node *starNode;
	int count = 1;
	while(temp->Next!=NULL){
		if(count==position){
			starNode = temp;
		}
		count++;
		temp = temp->Next;
	}
	temp->Next = starNode;
}
// Cycle detect
bool detectCycle(Node* &head){
	Node* slow = head;
	Node* fast = head;
	while(fast!=NULL && fast->Next!=NULL){
		slow = slow->Next;
		fast = fast->Next->Next;
		// cycle detection
		if(slow->Next == fast->Next){
			return true;
		}
	}
	return false;
}
// Remove Cycle :
void removeCycle(Node* &head){
	Node *slow = head;
	Node *fast = head;
	// s-1 : fast == slow
	do{
		slow = slow->Next;
		fast = fast->Next->Next;
	}while(fast!=slow);
	
	// S-2 : Re initialization of fast Node as a head
	fast = head;
	// S-3 : fast-Next == Slow-Next
	while(fast->Next != slow->Next){
		fast = fast->Next;
		slow = slow->Next;
	}
	slow->Next = NULL;
}
// Main function
int main()
{
    Node* head = NULL;
    int value;
    cout << "Choice 1: Insertion at Head" << endl
         << "Choice 2: Insertion at Tail" << endl
         << "Choice 3: Reversal of List (Recursive way) "<<endl
         << "Choice 4: Find Mid Value"<<endl
         << "Choice 5: Make Cycle in Linked List"<<endl
         << "Choice 6: Detect Cycle in Linked List"<<endl
         << "Choice 7: Remove Cycle in Linked list"<<endl
         << "Choice 0: Exit" << endl;

    int choice,position,key;
    cout  << "Next Choice: ";
    cin >> choice;

    while(choice != 0)
    {

        switch(choice)
        {
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
        	head = reverseRecursive(head);
        	break;
        case 4:
        	int mid;
        	mid = findMid(head);
        	if(mid==-1){
        		cout<<"The Linked List is empty! "<<endl;
			}else{
				cout<<"Mid value is: "<<mid<<endl;
			}
			break;
		case 5:
			cout<<"Enter the desire position to create Cycle: ";
			cin>>position;
			makeCycle(head,position);
			break;
		case 6:
			bool cycleStatus;
			cycleStatus = detectCycle(head);
			if( cycleStatus == true ){
				cout<<"There is a Cycle in Linked List"<<endl;
			}else{
				cout<<"There is No Cycle in linked list"<<endl;
			}
			break;
		case 7:
            cycleStatus = detectCycle(head);
           if(cycleStatus == true) {
              removeCycle(head);
          cout<<"Cycle removed successfully."<<endl;
         } else {
           cout<<"There is No Cycle in linked list"<<endl;
        }
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
