#include <bits/stdc++.h>
using namespace std;

// 🧩 Definition for binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// 🎯 Top View of Binary Tree using BFS and horizontal distance tracking
class Solution {
public:
    vector<int> topView(Node* root) {
        // 🧪 Edge case: empty tree
        if (!root) return {};

        // 📦 Queue for BFS: stores node and its horizontal distance (HD)
        queue<pair<Node*, int>> q;

        // 🌐 Map to store first node at each HD (topmost node)
        map<int, Node*> mp;

        q.push({root, 0}); // root is at HD = 0

        while (!q.empty()) {
            auto element = q.front();
            q.pop();

            Node* node = element.first;
            int line = element.second;

            // 🧮 Store node only if it's the first at this HD
            if (mp.find(line) == mp.end()) {
                mp[line] = node;
            }

            // 👈 Traverse left child with HD - 1
            if (node->left) {
                q.push({node->left, line - 1});
            }

            // 👉 Traverse right child with HD + 1
            if (node->right) {
                q.push({node->right, line + 1});
            }
        }

        // 📤 Extract top view from map in left-to-right order
        vector<int> ans;
        for (const auto& p : mp) {
            ans.push_back(p.second->data);
        }

        return ans;
    }
};

/* 🧪 Sample Tree Builder
   Example Tree:
         1
        / \
       2   3
        \
         4
          \
           5
            \
             6
   Top View: 2 1 3 6
*/
Node* buildSampleTree() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->right = new Node(5);
    root->left->right->right->right = new Node(6);
    return root;
}

// 🧵 Main function to test topView
int main() {
    Solution sol;
    Node* root = buildSampleTree();

    vector<int> result = sol.topView(root);

    cout << "Top View of Binary Tree:\n";
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