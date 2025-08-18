#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // Function to find the k-th largest element in the array
    int findKthLargest(vector<int>& nums, int k) {
        // Min-heap to keep track of the k largest elements
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int i = 0; i < nums.size(); i++) {
            minHeap.push(nums[i]); // Push current element

            // If heap size exceeds k, remove the smallest (top of min-heap)
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        // The top of the heap is the k-th largest element
        return minHeap.top();
    }
};

// 🧪 Main function for testing
int main() {
    Solution sol;
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;

    int result = sol.findKthLargest(nums, k);
    cout << "The " << k << "-th largest element is: " << result << endl;

    return 0;
}