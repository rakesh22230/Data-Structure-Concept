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
void print(treeNode *root, int level);
void LevelOrderTraversal(treeNode *root,string &chk);
void bondaryTraversal(treeNode *root);
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

// LevelOrderTraversal
void LevelOrderTraversal(treeNode *root,string &chk){
    if(root == NULL){
        return;
    }
    queue<treeNode*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        treeNode *chkNode = q.front();
        q.pop();
        if(chkNode!=NULL){
            cout<<chkNode->data<<" ";
            chk+=to_string(chkNode->data);
            if(chkNode->leftChild != NULL) {
                 q.push(chkNode->leftChild);
            }
            if(chkNode->rightChild != NULL){
                q.push(chkNode->rightChild);
            }
    
        } else{
            if(!q.empty()){
                q.push(NULL);
            }
        }
    }

}

// -------------------------Boundary Traversal-------------------------------------
void printleaves(treeNode *root){
    if(root == NULL) return;
    if(root->leftChild == NULL && root->rightChild == NULL){
        cout<<root->data<<" ";
        return;
    }

    printleaves(root->leftChild);
    printleaves(root->rightChild);

}

void printLeftNonleaves(treeNode *root){
     if(root == NULL) return;

     if(root->leftChild != NULL){
        cout<<root->data<<" ";
       printLeftNonleaves(root->leftChild);
     }

    else if(root->rightChild != NULL){
        cout<<root->data<<" ";
      printLeftNonleaves(root->rightChild);
     }

}
void printRightNonleaves(treeNode *root){
     if(root == NULL) return;

     if(root->rightChild != NULL){
        cout<<root->data<<" ";
       printRightNonleaves(root->rightChild);
     }

     else if(root->leftChild != NULL){
        cout<<root->data<<" ";
      printRightNonleaves(root->leftChild);
     }

}
void bondaryTraversal(treeNode *root){

    if(root == NULL) return;
    cout<<root->data <<" ";
    //  Left Non Leaves
    printLeftNonleaves(root->leftChild);
    // Left Leaves
    printleaves(root->leftChild);
    // Right Leaves
    printleaves(root->rightChild);
    // Right Non Leaves
    printRightNonleaves(root->rightChild);
}
// --------------------------Boundary Traversal Ends ---------------------------
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

    cout<<endl;
    cout<<"Printing the Binary Tree: "<<endl;
    print(allNode[0], 0);
    
    cout<<endl;    
    string labelordertraversal = " "; 
    cout<<"LabelOrder Traversal: ";
    LevelOrderTraversal(allNode[0],labelordertraversal);
    cout<<endl;
    cout<<"Boundary Traversal: ";
    bondaryTraversal(allNode[0]);
    cout<<endl;
    

    return 0;
}


/*


9
0 1 2
1 3 4
2 5 6
3 -1 -1
4 -1 -1
5 7 8
6 -1 -1
7 -1 -1
8 -1 -1



*/
