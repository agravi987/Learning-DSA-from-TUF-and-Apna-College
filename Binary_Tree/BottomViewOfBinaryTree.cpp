#include <bits/stdc++.h>
using namespace std;

// 🧩 Definition for binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// 🎯 Bottom View of Binary Tree using BFS and horizontal distance tracking
class Solution {
public:
    vector<int> bottomView(Node* root) {
        // 🧪 Edge case: empty tree
        if (!root) return {};

        // 📦 Queue for BFS: stores node and its horizontal distance (HD)
        queue<pair<Node*, int>> q;

        // 🌐 Map to store the latest node at each HD (bottommost node)
        map<int, Node*> mp;

        q.push({root, 0}); // root is at HD = 0

        while (!q.empty()) {
            auto element = q.front();
            q.pop();

            Node* node = element.first;
            int line = element.second;

            // 🧮 Overwrite node at this HD — ensures bottommost node is stored
            mp[line] = node;

            // 👈 Traverse left child with HD - 1
            if (node->left) {
                q.push({node->left, line - 1});
            }

            // 👉 Traverse right child with HD + 1
            if (node->right) {
                q.push({node->right, line + 1});
            }
        }

        // 📤 Extract bottom view from map in left-to-right order
        vector<int> ans;
        for (const auto& p : mp) {
            ans.push_back(p.second->data);
        }

        return ans;
    }
};

/* 🧪 Sample Tree Builder
   Example Tree:
         20
        /  \
       8   22
      / \    \
     5  3    25
       / \
      10 14

   Bottom View: 5 10 3 14 25
*/
Node* buildSampleTree() {
    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(5);
    root->left->right = new Node(3);
    root->right->right = new Node(25);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    return root;
}

// 🧵 Main function to test bottomView
int main() {
    Solution sol;
    Node* root = buildSampleTree();

    vector<int> result = sol.bottomView(root);

    cout << "Bottom View of Binary Tree:\n";
    for (int val : result) {
        cout << val << " ";
    }
    cout << "\n";

    return 0;
}

/* 📊 Time & Space Complexity Analysis

Time Complexity:
- BFS traversal: O(N), where N = number of nodes
- Map insertion: O(log K) per insert, where K = number of unique horizontal distances
=> Overall: O(N log K), typically O(N log N) in worst case

Space Complexity:
- Map storage: O(K) for horizontal distances
- Queue: O(N) in worst case
=> Overall: O(N)
*/