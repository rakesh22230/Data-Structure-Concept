#include<bits/stdc++.h>
using namespace std;

// function declare 
void heapify(int ar[], int n, int curr);
void print(int ar[], int n);
void heapsort(int ar[], int size);

// swap two integer values by pointer
void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// maintain max-heap property for subtree rooted at curr
void heapify(int ar[], int n, int curr){
    int leftChild = 2 * curr + 1;
    int rightChild = 2 * curr + 2;
    int largest = curr;

    // find largest among curr, left child, and right child
    if (leftChild < n && ar[leftChild] > ar[largest]){
        largest = leftChild;
    }
    if (rightChild < n && ar[rightChild] > ar[largest]){
        largest = rightChild;
    }

    // if largest is not the current node, swap and recurse
    if (largest != curr) {
        swap(ar[curr], ar[largest]);
        heapify(ar, n, largest);
    }
}

// print array elements
void print(int ar[], int n){
    for (int i = 0; i < n; i++) {
        cout << ar[i] << " ";
    }
    cout << endl;
}

// sort the array using heap sort
void heapsort(int ar[], int size){
    for (int i = size - 1; i >= 0; i--){
        // move current root to end and rebuild heap
        swap(ar[0], ar[i]);
        heapify(ar, i, 0);
    }
}

int main(){
    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n; i++){
        cin >> ar[i];   // input array
    }

    int leafNode = (n / 2) - 1; // index of last non-leaf node

    cout << "Before Heapify: ";
    print(ar, n);

    // build max-heap from the array
    for (int i = leafNode; i >= 0; i--){
        heapify(ar, n, i);
    }

    cout << "After Heapify: ";
    print(ar, n);
    
    cout << "After the Heapsort: ";
    heapsort(ar, n); // perform heap sort
    print(ar, n);

    return 0;
}
