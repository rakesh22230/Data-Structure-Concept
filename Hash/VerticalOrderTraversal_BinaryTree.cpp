#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

// Function to construct the binary tree
TreeNode* ConstructBinaryTree() {

    int n;  
    cin >> n;  
    vector<TreeNode*> allNode(n); 

    // Create all nodes with default value -1
    for (int i = 0; i < n; i++) {
        allNode[i] = new TreeNode(-1);
    }

    for (int i = 0; i < n; i++) {
        int value, left, right;
        cin >> value >> left >> right;
        allNode[i]->val = value;

        if (left != -1) {
            allNode[i]->left = allNode[left];
        }
        if (right != -1) {
            allNode[i]->right = allNode[right];
        }
    }

    return allNode[0]; 
}

// ---------------- Vertical Order Traversal ---------------- >

void VerticalOrderTraversal(TreeNode* root,int D, map<int,vector<int>> &M){
      if(root == NULL ) return;
      M[D].push_back(root->val);
      VerticalOrderTraversal(root->left,D-1,M);  
      VerticalOrderTraversal(root->right,D+1,M); 
}

int main() {
    TreeNode* root = ConstructBinaryTree(); 

    map<int,vector<int>> M;
    VerticalOrderTraversal(root,0,M);  

    for( auto i : M){
        cout<<i.first<<": ";
        for(int j=0; j < i.second.size(); j++ ){
            cout<<i.second[j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
