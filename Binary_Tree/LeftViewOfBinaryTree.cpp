#include <bits/stdc++.h>
using namespace std;

// 🧩 Binary Tree Node Definition
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    // 🔁 Preorder Traversal (Root → Left → Right)
    // Captures the first node at each level (leftmost)
    void preOrder(Node* root, int level, map<int, Node*>& mp) {
        if (root == nullptr) return;

        // 🧮 Store node only if it's the first at this level
        if (mp.find(level) == mp.end()) {
            mp[level] = root;
        }

        preOrder(root->left, level + 1, mp);
        preOrder(root->right, level + 1, mp);
    }

    // 🎯 Returns the left view of the binary tree
    vector<int> leftView(Node* root) {
        map<int, Node*> mp;
        preOrder(root, 0, mp);

        vector<int> ans;
        for (auto& p : mp) {
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
      /     \
     4       5

   Left View: 1 2 4
*/
Node* buildSampleTree() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);
    return root;
}

// 🧵 Main function to test leftView
int main() {
    Solution sol;
    Node* root = buildSampleTree();

    vector<int> result = sol.leftView(root);

    cout << "Left View of Binary Tree:\n";
    for (int val : result) {
        cout << val << " ";
    }
    cout << "\n";

    return 0;
}

/* 📊 Time & Space Complexity Analysis

Time Complexity:
- Each node is visited once: O(N)
- Map insertion: O(log L) per insert, where L = number of levels
=> Overall: O(N log L), typically O(N)

Space Complexity:
- Map storage: O(L)
- Recursion stack: O(H), where H = height of tree
=> Overall: O(H + L), typically O(N)
*/