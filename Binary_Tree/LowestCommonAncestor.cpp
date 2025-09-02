#include <iostream>
using namespace std;

/** 
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    /**
     * Finds the lowest common ancestor (LCA) of two nodes in a binary tree.
     * 
     * @param root The root of the binary tree.
     * @param p First target node.
     * @param q Second target node.
     * @return The LCA node of p and q.
     */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: if root is null or matches either p or q, return root
        if (root == nullptr || root == p || root == q)
            return root;

        // Recursively search in left and right subtrees
        TreeNode* inLeft = lowestCommonAncestor(root->left, p, q);
        TreeNode* inRight = lowestCommonAncestor(root->right, p, q);

        // If both sides return non-null, current node is the LCA
        if (inLeft && inRight)
            return root;

        // Otherwise, return the non-null result (either left or right)
        return inLeft ? inLeft : inRight;
    }
};

/**
 * Helper function to build a simple binary tree for testing.
 */
TreeNode* buildTestTree() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    return root;
}

int main() {
    Solution sol;
    TreeNode* root = buildTestTree();

    TreeNode* p = root->left;        // Node 5
    TreeNode* q = root->right;       // Node 1

    TreeNode* lca = sol.lowestCommonAncestor(root, p, q);
    if (lca)
        cout << "Lowest Common Ancestor of " << p->val << " and " << q->val << " is: " << lca->val << endl;
    else
        cout << "No common ancestor found." << endl;

    return 0;
}