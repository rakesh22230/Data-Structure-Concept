#include <bits/stdc++.h>
using namespace std;

// Create tree node
class treeNode {
public:
    int data;
    treeNode *leftChild;
    treeNode *rightChild;

    treeNode(int value) {
        data = value;
        leftChild = NULL;
        rightChild = NULL;
    }
};

// Function declarations
void print(treeNode *root, int level);
void Spaceprint(int level);

// Print function
void print(treeNode *root, int level) {
    if (root == NULL) { // root is empty
        return;
    }

    if (root->leftChild == NULL && root->rightChild == NULL) { // Case - 1
        cout << root->data << endl;
        return;
    } else { // Case - 2
        cout << endl;
        Spaceprint(level);
        cout << "Root: " << root->data << endl;
    }

    if (root->leftChild != NULL) {
        Spaceprint(level);
        cout << "Left: ";
        print(root->leftChild, level + 1);
    }

    if (root->rightChild != NULL) {
        Spaceprint(level);
        cout << "Right: ";
        print(root->rightChild, level + 1);
    }
}

// Space print function
void Spaceprint(int level) {
    for (int i = 0; i < level; i++) {
        cout << "   ";
    }
}

int main() {
    int n;
    cin >> n;
    treeNode *allNode[n];

    // Initialize all nodes with value -1
    for (int i = 0; i < n; i++) {
        allNode[i] = new treeNode(-1);
    }

    for (int i = 0; i < n; i++) {
        int value, left, right;
        cin >> value >> left >> right;
        allNode[i]->data = value;

        if (left != -1) {
            allNode[i]->leftChild = allNode[left];
        }
        if (right != -1) {
            allNode[i]->rightChild = allNode[right];
        }
    }

    print(allNode[0], 0);

    return 0;
}
