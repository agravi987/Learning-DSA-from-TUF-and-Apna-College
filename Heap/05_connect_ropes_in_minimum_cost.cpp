#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int minCost(vector<int>& arr) {
        // Step 1: Create a min-heap to store all elements
        // Time: O(n log n) — inserting n elements into heap
        // Space: O(n) — heap stores all elements
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int val : arr) {
            minHeap.push(val);
        }

        int totalCost = 0;

        // Step 2: Continuously combine the two smallest elements
        // Each operation: O(log n) for push/pop
        // Total operations: n - 1 merges → O(n log n)
        while (minHeap.size() > 1) {
            int first = minHeap.top(); minHeap.pop();
            int second = minHeap.top(); minHeap.pop();

            int sum = first + second;
            minHeap.push(sum); // Push the combined cost back

            totalCost += sum; // Accumulate total cost
        }

        // Final result: minimum total cost to combine all elements
        return totalCost;
    }
};

// 🧪 Main function for testing
int main() {
    Solution sol;
    vector<int> arr = {4, 3, 2, 6};

    int cost = sol.minCost(arr);
    cout << "Minimum total cost to combine elements: " << cost << endl;

    return 0;
}