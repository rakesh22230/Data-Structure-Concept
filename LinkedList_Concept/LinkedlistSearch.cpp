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
void insertAtSpecificPostion(Node* &head,int position,int val);
int searchByKeyUnique(Node* &head,int key);
void display(Node* n);
int countLength(Node* &head);
void searchByKeyDuplicate(Node* &head,int key);
Test searchByKeyDuplicateReturn(Node* &head,int key);
void deleteAtHead(Node* &head);
void deleteAtTail(Node* &head);
void deletionAtSpecificPosition(Node* &head,int position);
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
// Insertion at specific Postion
void insertAtSpecificPostion(Node* &head,int position,int val)
{
    Node* temp = head;
    int i = 0;
    while(i<position-2)
    {
        temp = temp->Next;
        i++;
    }
    Node* newNode = new Node(val);
    newNode->Next = temp->Next;
    temp->Next = newNode;
}

// Search by key in unique linked list
int searchByKeyUnique(Node* &head,int key)
{
    int count = 1;
    Node* temp = head;
    if(head==NULL)
    {
        return -1;
    }
    while(temp->value !=key)
    {

        if(temp->Next == NULL)
        {
            return -1;
        }
        temp = temp->Next;
        count++;

    }
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
// Search by key in duplicate Linked list :
void searchByKeyDuplicate(Node* &head,int key)
{
    Node* temp = head;
    int count = 1;
    int flag = 0;
    int size;
    size = countLength(head);
    int pos[size],k=1;
    while(temp!=NULL)
    {
        if(temp->value == key)
        {
            pos[k] = count;
            flag = 1;
            k++;
        }
        temp = temp->Next;
        count++;
    }
    if(flag==0) cout<<"The search value is not yet in this list."<<endl;
    else
    {
        pos[0]= k;
        cout<<"The value is found at position: ";
        for(int i=1; i<pos[0]; i++)
        {
            cout<<pos[i];
            if(i<pos[0]) cout<<",";
        }
        cout<<endl;
    }
}
// Search by key value return from duplicate linked list
Test searchByKeyDuplicateReturn(Node* &head,int key)
{
    Node* temp = head;
    int count = 1;
    int k = 1;
    Test T;
    while(temp!=NULL)
    {
        if(temp->value == key)
        {
            T.pos[k] = count;
            k++;
        }
        temp = temp->Next;
        count++;
    }
    T.pos[0] = k;
    return T;


}
// Deletetion at Head
void deleteAtHead(Node* &head)
{
    Node* temp = head;
    if(temp!=NULL)
    {
        head = temp->Next;
        delete temp;
    }
    else
    {
        cout<<"The empty linked list.";
    }

}
// Deletetion at Tail
void deleteAtTail(Node* &head)
{
    Node* temp = head;
    if(head!=NULL && temp->Next!=NULL)
    {
        while(temp->Next->Next!=NULL)
        {
            temp = temp->Next;
        }
        Node* delNode = temp->Next;
        temp->Next = NULL;
        delete delNode;
    }
    else
    {
        if(head==NULL) cout<<"The linked list empty!";
        else deleteAtHead(head);
    }
}
// Deletion at a specific position
void deletionAtSpecificPosition(Node* &head,int position)
{
    Node* temp = head;
    if(temp!=NULL && position<=countLength(head))
    {
        if(position==1)
        {
            deleteAtHead(head);
        }
        else if(position==countLength(head))
        {
            deleteAtTail(head);
        }
        else
        {
        	int i=1;
            while(i<position-1)
            {
                temp = temp->Next;
                i++;
            }
            Node* delNode =temp->Next;
            temp->Next = delNode->Next;
            delete delNode;

        }


    }
    else
    {
        if(countLength(head)<position)
        {
            cout<<"Position Out of Boundary"<<endl;
        }
        else
        {
            cout<<"There is no value in linked list."<<endl;
        }
    }


}
// Deletion by value unique ( Linked List )
void deletionByValueUnique(Node* &head,int value){
	// find the position of the value
	int position;
	position = searchByKeyUnique(head,value);
	if(position==-1){
		cout<<"Value is not found in this linked list"<<endl;
	}else{
		deletionAtSpecificPosition(head,position);
	}
	
	// Delete the node at the position
}
// Main function
int main()
{
    Node* head = NULL;
    int value;
    cout << "Choice 1: Insertion at Head" << endl
         << "Choice 2: Insertion at Tail" << endl
         << "Choice 3: Insertion at Specific Postion"<<endl
         << "Choice 4: Search by value ( Unique linked list ) "<<endl
         << "Choice 5: Search by value ( Duplicate linked list ) "<<endl
         << "Choice 6: Search by Return Value ( Duplicate linked list ) "<<endl
         << "Choice 7: Deletion At Head"<<endl
         << "Choice 8: Deletion At Tail"<<endl
         << "Choice 9: Deletion At a specific position"<<endl
         << "Choice 10: Deletion By value with Unique linked list."<<endl
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
            cout<<"Enter the desired position: ";
            cin>>position;
            cout<<"Enter the value: ";
            cin>>value;
            insertAtSpecificPostion(head,position,value);
            break;
        case 4:
            cout<<"Enter the key value for search: ";
            cin>>key;
            position = searchByKeyUnique(head,key);
            if(position != -1)
            {
                cout<<"The key index value of : "<<position<<endl;
            }
            else
            {
                cout<<"The key is not found!"<<endl;
            }
            break;
        case 5:
            cout<<"Enter the key value for search: ";
            cin>>key;
            searchByKeyDuplicate(head,key);
            break;
        case 6:
            cout<<"Enter the key value for search: ";
            cin>>key;
            Test T;
            T = searchByKeyDuplicateReturn(head, key);
            if(T.pos[0]==1)
            {
                cout<<"The search value is not yet in this list."<<endl;
            }
            else
            {
                cout<<"The value is found at position: ";
                int size = T.pos[0];
                for(int i=1; i<size; i++)
                {
                    cout<<T.pos[i];
                    if(i<size) cout<<",";
                }
                cout<<endl;
            }
            break;
        case 7:
            deleteAtHead(head);
            display(head);
            break;
        case 8:
            deleteAtTail(head);
            display(head);
            break;
        case 9:
            cout<<"Enter a speicipic position: ";
            cin>>position;
            deletionAtSpecificPosition(head,position);
            break;
        case 10:
        	int val;
        	cout<<"Enter a value: ";
        	cin>>val;
        	deletionByValueUnique(head,val);
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
