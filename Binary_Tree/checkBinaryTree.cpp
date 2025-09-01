#include <iostream>
#include <cmath>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Solution class to check if a binary tree is height-balanced
class Solution {
public:
    // Helper function: returns height if balanced, else -1
    int check(TreeNode* root) {
        if (root == nullptr) return 0;

        int lh = check(root->left);
        int rh = check(root->right);

        // If any subtree is unbalanced, propagate -1
        if (lh == -1 || rh == -1) return -1;

        // If current node is unbalanced
        if (abs(lh - rh) > 1) return -1;

        // Return height of current subtree
        return max(lh, rh) + 1;
    }

    // Main function to check balance status
    bool isBalanced(TreeNode* root) {
        return check(root) != -1;
    }
};

// 🧪 Main function for testing
int main() {
    /*
        Constructing the following tree:
                1
               / \
              2   3
             /
            4
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    Solution sol;
    if (sol.isBalanced(root))
        cout << "Tree is balanced ✅" << endl;
    else
        cout << "Tree is NOT balanced ❌" << endl;

    // Clean up memory (optional for small test cases)
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}