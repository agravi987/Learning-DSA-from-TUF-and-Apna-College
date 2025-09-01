#include <bits/stdc++.h>
using namespace std;

// 🧩 Definition for binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // 🔁 Reverse Preorder Traversal (Root → Right → Left)
    // Stores the first node encountered at each level (rightmost)
    void reversePreOrder(TreeNode* root, int level, map<int, TreeNode*>& mp) {
        if (root == nullptr) return;

        // 🧮 Store node only if it's the first at this level
        if (mp.find(level) == mp.end()) {
            mp[level] = root;
        }

        // 👉 Traverse right subtree first
        reversePreOrder(root->right, level + 1, mp);

        // 👈 Then traverse left subtree
        reversePreOrder(root->left, level + 1, mp);
    }

    // 🎯 Returns the right side view of the binary tree
    vector<int> rightSideView(TreeNode* root) {
        map<int, TreeNode*> mp;
        reversePreOrder(root, 0, mp);

        vector<int> ans;
        for (const auto& p : mp) {
            ans.push_back(p.second->val);
        }

        return ans;
    }
};

/* 🧪 Sample Tree Builder
   Example Tree:
         1
        / \
       2   3
        \   \
         5   4

   Right Side View: 1 3 4
*/
TreeNode* buildSampleTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);
    return root;
}

// 🧵 Main function to test rightSideView
int main() {
    Solution sol;
    TreeNode* root = buildSampleTree();

    vector<int> result = sol.rightSideView(root);

    cout << "Right Side View of Binary Tree:\n";
    for (int val : result) {
        cout << val << " ";
    }
    cout << "\n";

    return 0;
}

/* 📊 Time & Space Complexity Analysis

Time Complexity:
- Reverse preorder traversal visits each node once: O(N)
- Map insertion: O(log L) per insert, where L = number of levels
=> Overall: O(N log L), typically O(N)

Space Complexity:
- Map storage: O(L) for levels
- Recursion stack: O(H), where H = height of tree
=> Overall: O(H + L), typically O(N) in worst case
*/