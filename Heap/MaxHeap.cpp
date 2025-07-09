#include<bits/stdc++.h>
using namespace std;
void swap(int *a, int *b){
    int temp;
     temp = *a;
    *a = *b;
    *b = temp;

}
void heapify(int ar[],int n,int curr){
    int leftChild = 2*curr + 1;
    int rightChild = 2*curr + 2;

    int largest = curr;

    if( leftChild < n &&  ar[leftChild] > ar[largest]){
        largest = leftChild;
    }

    if( rightChild < n &&  ar[rightChild] > ar[largest] ){
        largest = rightChild;
    }

    if( largest != curr ) {
        swap(ar[curr] , ar[largest]);
        heapify(ar,n,largest);
    }
}
void print(int ar[],int n){
    for(int i=0; i < n ; i++) {
        cout<<ar[i]<<" ";
    }
    cout<<endl;
}
int main(){

    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    int leafNode = (n/2)-1;

    cout<<"Before Heapify: ";
    print(ar,n);

    for(int i= leafNode;i>=0;i--){
        heapify(ar,n,i);
    }
    cout<<"After Heapify: ";
    print(ar,n);


    return 0;
}
