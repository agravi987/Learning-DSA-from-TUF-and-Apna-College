#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // 🔹 Helper function to find the k-th smallest element using a max-heap
    // Time: O(n log k), Space: O(k)
    long long kthSmallestElement(long long arr[], int n, int k) {
        priority_queue<int> maxHeap;

        for (int i = 0; i < n; i++) {
            maxHeap.push(arr[i]);

            // Keep only k smallest elements in the heap
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        // Top of max-heap is the k-th smallest element
        return maxHeap.top();
    }

    // 🔹 Main function to compute sum of elements strictly between K1-th and K2-th smallest
    // Time: O(n log k) for each kthSmallestElement + O(n) for sum loop → Total: O(n log k)
    // Space: O(k) for each heap
    long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2) {
        long long low = kthSmallestElement(A, N, K1);   // K1-th smallest
        long long high = kthSmallestElement(A, N, K2);  // K2-th smallest

        long long sum = 0;

        // Traverse array and sum elements strictly between low and high
        for (int i = 0; i < N; i++) {
            if (A[i] > low && A[i] < high) {
                sum += A[i];
            }
        }

        return sum;
    }
};

// 🧪 Main function for testing
int main() {
    Solution sol;
    long long A[] = {1, 3, 12, 5, 15, 11};
    long long N = sizeof(A) / sizeof(A[0]);
    long long K1 = 3, K2 = 6;

    long long result = sol.sumBetweenTwoKth(A, N, K1, K2);
    cout << "Sum of elements between " << K1 << "-th and " << K2 << "-th smallest: " << result << endl;

    return 0;
}