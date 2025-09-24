/*
Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    // Helper function to recursively clone each node using DFS
    Node* cloneHelper(Node* node, unordered_map<Node*, Node*>& mp) {
        // Time Complexity: O(N) — each node is visited once
        // Space Complexity: O(N) — due to recursion stack and hash map

        Node* newNode = new Node(node->val); // clone current node
        mp[node] = newNode; // map original to clone

        for (auto neighbor : node->neighbors) {
            // If neighbor not cloned yet, recurse
            if (mp.find(neighbor) == mp.end()) {
                newNode->neighbors.push_back(cloneHelper(neighbor, mp));
            } else {
                // Already cloned → reuse
                newNode->neighbors.push_back(mp[neighbor]);
            }
        }

        return newNode;
    }

    Node* cloneGraph(Node* node) {
        // Time Complexity: O(N)
        // Space Complexity: O(N)

        if (!node) return nullptr;

        unordered_map<Node*, Node*> mp; // Original → Clone mapping
        return cloneHelper(node, mp);
    }
};