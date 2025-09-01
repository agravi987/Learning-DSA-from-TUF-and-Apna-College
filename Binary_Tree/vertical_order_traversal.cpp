#include <bits/stdc++.h>
using namespace std;

// 🧩 Definition for a binary tree node
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // 🌐 Map structure: vertical -> level -> multiset of node values
        map<int, map<int, multiset<int>>> nodes;

        // 📦 Queue for BFS: stores node and its (vertical, level) position
        queue<pair<TreeNode*, pair<int, int>>> que;
        que.push({root, {0, 0}});

        // 🔁 BFS traversal to populate the map
        while (!que.empty()) {
            auto element = que.front();
            que.pop();

            TreeNode* node = element.first;
            int vertical = element.second.first;
            int level = element.second.second;

            // 🧮 Insert node value into corresponding vertical and level
            nodes[vertical][level].insert(node->val);

            // 👈 Traverse left child
            if (node->left)
                que.push({node->left, {vertical - 1, level + 1}});

            // 👉 Traverse right child
            if (node->right)
                que.push({node->right, {vertical + 1, level + 1}});
        }

        // 📤 Construct final answer from the map
        vector<vector<int>> ans;
        for (const auto& p : nodes) {
            vector<int> col;
            for (const auto& q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};

/* 🧪 Sample Tree Builder
   Example Tree:
         3
        / \
       9   20
           / \
          15  7
   Expected Vertical Traversal:
   [
     [9],
     [3, 15],
     [20],
     [7]
   ]
*/
TreeNode* buildSampleTree() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    return root;
}

// 🧵 Main function to test verticalTraversal
int main() {
    Solution sol;
    TreeNode* root = buildSampleTree();

    vector<vector<int>> result = sol.verticalTraversal(root);

    cout << "Vertical Order Traversal:\n";
    for (const auto& col : result) {
        for (int val : col)
            cout << val << " ";
        cout << "\n";
    }

    return 0;
}

/* 📊 Time & Space Complexity Analysis

Time Complexity:
- BFS traversal: O(N), where N = number of nodes
- Insertion into multiset: O(log k) per insert, where k = number of elements at that level
- Final traversal of map: O(N)
=> Overall: O(N log k), typically O(N log N) in worst case due to multiset insertions

Space Complexity:
- Map storage: O(N) for all nodes
- Queue: O(N) in worst case
=> Overall: O(N)
*/