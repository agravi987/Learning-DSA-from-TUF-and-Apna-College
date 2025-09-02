#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

/**
 * Definition for a binary tree node.
 */
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
    /**
     * Calculates the maximum width of a binary tree.
     * Width is defined as the number of nodes between the leftmost and rightmost non-null nodes at each level.
     * 
     * @param root The root of the binary tree.
     * @return The maximum width across all levels.
     */
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        int maxWidth = 0;
        // Queue stores pairs of (node, index) where index simulates position in a complete binary tree
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();
            // Normalize indices to prevent overflow
            unsigned long long minIndex = q.front().second;
            unsigned long long first = 0, last = 0;

            for (int i = 0; i < size; ++i) {
                auto [node, index] = q.front();
                q.pop();
                unsigned long long curIndex = index - minIndex;

                if (i == 0) first = curIndex;
                if (i == size - 1) last = curIndex;

                if (node->left)
                    q.push({node->left, curIndex * 2 + 1});
                if (node->right)
                    q.push({node->right, curIndex * 2 + 2});
            }

            maxWidth = max(maxWidth, static_cast<int>(last - first + 1));
        }

        return maxWidth;
    }
};

/**
 * Dry-run ready main function to test the algorithm.
 */
int main() {
    Solution sol;

    // Constructing the binary tree:
    //         1
    //        / \
    //       3   2
    //      /     \
    //     5       9
    //    /         \
    //   6           7
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->right->right = new TreeNode(9);
    root->left->left->left = new TreeNode(6);
    root->right->right->right = new TreeNode(7);

    int width = sol.widthOfBinaryTree(root);
    cout << "Maximum width of the binary tree is: " << width << endl;

    return 0;
}

// Time Complexity: O(N)
// - Each node is visited once during level-order traversal.
// - N is the total number of nodes in the tree.

// Space Complexity: O(N)
// - In the worst case, the queue holds all nodes at the widest level.