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
TreeNode* SearchBST(TreeNode* root, int val);
TreeNode* insucess(TreeNode* root);
TreeNode* DeletionBST(TreeNode* root,int val);

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
        cout<<root->val<<"-> ";
        SearchBST(root->left,val);
    } 
    // value greather than root
    else{
        cout<<root->val<<"-> ";
        SearchBST(root->right,val);
    }
    
}
// Insuccessor Node
TreeNode* insucess(TreeNode* root){
    TreeNode* curr = root;
    while( curr->left != NULL ){
        curr = curr->left;
    }
    return curr;
}

// Deletion BST 
TreeNode* DeletionBST(TreeNode* root,int val){
    if(root == NULL ) return NULL;
    // First we have to travasel to reach this delete Node
    if( val < root->val){
        root->left = DeletionBST(root->left,val);
    }
    else if( val > root->val) {
        root->right = DeletionBST(root->right,val);
    } 
    // Implementation Part two solve 3 case 
    else {

        if( root->left == NULL ) {    // case 1 :  Delete Node have a one children || Case 2 : Delete node is a leaf Node
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } 
        else if( root->right == NULL ) {  // Case 1 :  Delete Node have a one Childreen 
            TreeNode* temp = root->left;
            delete root;
            return temp;
        } 
        else{
            // Delete Node have a two children or successor root
            TreeNode* temp = insucess(root->right);
            root->val = temp->val;
            root->right = DeletionBST(root->right, temp->val);
        }
        

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
     InOrdertraversal(root,IOT);
     cout<<IOT<<endl;

     int key;
     cout<<"Enter your value want to search: ";
     cin>>key;

     if( SearchBST(root,key) == NULL ){
        cout<<endl<<"Value doesn't exits in the list."<<endl;
     } else{
        cout<<endl<<"Value exits in the list."<<endl;
     }  

     int value;
     cout<<"Enter your value you want to delete: ";
     cin>>value;

     root = DeletionBST(root,value);
     string afterDelete="";
     InOrdertraversal(root,afterDelete);
     cout<<afterDelete<<endl;



    return 0;
}


