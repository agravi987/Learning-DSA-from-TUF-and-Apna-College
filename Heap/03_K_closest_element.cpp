#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    /*
     * Function to find k closest elements to x in the array.
     *
     * Time Complexity:
     * - Building the heap: O(n log k), where n is the size of arr
     *   (each insertion takes O(log k), and we keep heap size ≤ k)
     * - Extracting k elements: O(k log k) for sorting the result
     * - Total: O(n log k + k log k) ≈ O(n log k)
     *
     * Space Complexity:
     * - O(k) for the heap and result vector
     */
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // Max-heap to store pairs of (absolute difference, element)
        priority_queue<pair<int, int>> maxHeap;

        // Traverse the array and maintain a heap of size k
        for (int i = 0; i < arr.size(); i++) {
            int diff = abs(arr[i] - x);
            maxHeap.push({diff, arr[i]});

            // If heap size exceeds k, remove the element with largest difference
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        // Extract elements from the heap
        vector<int> ans;
        while (!maxHeap.empty()) {
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        // Sort the result as required by the problem
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution sol;

    // Sample input
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    int x = 3;

    // Call the function
    vector<int> result = sol.findClosestElements(arr, k, x);

    // Print the result
    cout << "Closest " << k << " elements to " << x << " are: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}