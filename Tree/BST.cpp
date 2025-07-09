#include<bits/stdc++.h>
using namespace std;
// create class 
class TreeNode{
    public:
       int val;
       TreeNode *left;
       TreeNode *right;
    TreeNode(int val){
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

// Function Decleararion 
void InOrdertraversal(TreeNode* root, string &s);
TreeNode* Construct_BST(TreeNode* root,int val);

// In Order Traversal
void InOrdertraversal(TreeNode* root, string &s){

    if(root == NULL ) return;
    // left 
     InOrdertraversal(root->left,s);
    // root 
    s = s + (to_string(root->val) )+" ";
    // right
    InOrdertraversal(root->right,s);
}
// Construc BST
TreeNode* Construct_BST(TreeNode* root,int val){
    TreeNode* newNode = new TreeNode(val);
    // If There is No Node or root is NuLL
    if(root == NULL){
        root = newNode;
        return root;
    }
    // val < root->val  --------- root->left
    if( val < root->val) {
        root->left = Construct_BST(root->left,val);
    }
    // val > root->val ----- > root->right
    else if( val > root->val){
        root->right = Construct_BST(root->right,val);
    }
    return root;
}

// Search BST
TreeNode* SearchBST(TreeNode* root, int val){
    if(root == NULL) return NULL;

    // value is equal is root value
    if( root->val == val) {
        cout<<root->val;
        return root;
    }

    // value less than root
    if( val < root->val){
        cout<<root->val<<"->";
        SearchBST(root->left,val);
    } 
    // value greather than root
    else{
        cout<<root->val<<"->";
        SearchBST(root->right,val);
    }
    
}
int main(){
     int n;
     cin>>n;
     TreeNode* root = NULL;
     for(int i=0;i<n;i++){
        int value;
        cin>>value;
       root =  Construct_BST(root,value);
     }
     string IOT="";
     //InOrdertraversal(root,IOT);
     //cout<<IOT<<endl;

     int key;
     cout<<"Enter your value want to search: ";
     cin>>key;

     if( SearchBST(root,key) == NULL ){
        cout<<endl<<"Value doesn't exits in the list."<<endl;
     } else{
        cout<<endl<<"Value exits in the list."<<endl;
     }


    return 0;
}
