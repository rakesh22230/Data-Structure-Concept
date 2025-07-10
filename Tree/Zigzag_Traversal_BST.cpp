#include<bits/stdc++.h>
using namespace std;

// TreeNode class
class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

// Function declarations
void InOrderTraversal(TreeNode* root, string &s);
TreeNode* Construct_BST(TreeNode* root, int val);
void ZigZagTraversal(TreeNode* root);


// Construct BST
TreeNode* Construct_BST(TreeNode* root, int val) {
    if (root == NULL) return new TreeNode(val);
    if (val < root->val)
        root->left = Construct_BST(root->left, val);
    else if (val > root->val)
        root->right = Construct_BST(root->right, val);
    return root;
}

// ZigZag Traversal Function
void ZigZagTraversal(TreeNode* root) {
    if (!root) return;

    stack<TreeNode*> currentLevel;
    stack<TreeNode*> nextLevel;
    bool leftToRight = true;

    currentLevel.push(root);

    while (!currentLevel.empty()) {
        TreeNode* node = currentLevel.top();
        currentLevel.pop();

        if (node) {
            cout << node->val << " ";

            // Left to Right
            if (leftToRight) {
                if (node->left)
                    nextLevel.push(node->left);
                if (node->right)
                    nextLevel.push(node->right);
            }
            // Right to Left
            else {
                if (node->right)
                    nextLevel.push(node->right);
                if (node->left)
                    nextLevel.push(node->left);
            }
        }

        if (currentLevel.empty()) {
            leftToRight = !leftToRight;
            swap(currentLevel, nextLevel);
        }
    }
}

int main() {
    int n;
    cin >> n;
    TreeNode* root = NULL;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        root = Construct_BST(root, value);
    }

    cout << "ZigZag Traversal: ";
    ZigZagTraversal(root);
    cout << endl;

    return 0;
}
