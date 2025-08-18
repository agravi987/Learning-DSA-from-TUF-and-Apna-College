#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // Function to find the k-th smallest element in the array
    int kthSmallest(vector<int> &arr, int k) {
        // Max-heap to keep track of the k smallest elements
        priority_queue<int> max_heap;

        for (int i = 0; i < arr.size(); i++) {
            max_heap.push(arr[i]); // Push current element

            // If heap size exceeds k, remove the largest (top of max-heap)
            if (max_heap.size() > k) {
                max_heap.pop();
            }
        }

        // The top of the heap is the k-th smallest element
        return max_heap.top();
    }
};

// 🧪 Main function for testing
int main() {
    Solution sol;
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;

    int result = sol.kthSmallest(arr, k);
    cout << "The " << k << "-th smallest element is: " << result << endl;

    return 0;
}