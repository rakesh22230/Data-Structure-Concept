#include <bits/stdc++.h>
using namespace std;

// Tree node
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
void Inorder(treeNode *root, string &chk);
void Preorder(treeNode *root, string &chk);
void Postorder(treeNode *root, string &chk);

// Print tree
void print(treeNode *root, int level) {
    if (root == NULL) return;

    if (root->leftChild == NULL && root->rightChild == NULL) {
        cout << root->data << endl;
        return;
    } else {
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

// Print spaces
void Spaceprint(int level) {
    for (int i = 0; i < level; i++) {
        cout << "   ";
    }
}

// Inorder: Left Root Right
void Inorder(treeNode *root, string &chk) {
    if (root == NULL) return;
    Inorder(root->leftChild, chk);
    chk += to_string(root->data);
    Inorder(root->rightChild, chk);
}

// Preorder: Root Left Right
void Preorder(treeNode *root, string &chk) {
    if (root == NULL) return;
    chk += to_string(root->data);
    Preorder(root->leftChild, chk);
    Preorder(root->rightChild, chk);
}

// Postorder: Left Right Root
void Postorder(treeNode *root, string &chk) {
    if (root == NULL) return;
    Postorder(root->leftChild, chk);
    Postorder(root->rightChild, chk);
    chk += to_string(root->data);
}

int main() {
    int n;
    cin >> n;
    treeNode *allNode[n];

    // Initialize all nodes
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

    string InOrdertraversal = " ";
    string PreOrdertraversal = " ";
    string PostOrdertraversal = " ";

    Inorder(allNode[0], InOrdertraversal);
    Preorder(allNode[0], PreOrdertraversal);
    Postorder(allNode[0], PostOrdertraversal);

    cout << "InOrder Traversal  : " << InOrdertraversal << endl;
    cout << "PreOrder Traversal : " << PreOrdertraversal << endl;
    cout << "PostOrder Traversal: " << PostOrdertraversal << endl;
    cout<<endl;

    return 0;
}
