#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq;

        // Step 1: Count frequency of each number
        // Time: O(n), Space: O(n) — for storing frequency of each unique number
        for (int num : nums) {
            freq[num]++;
        }

        // Step 2: Sort using custom comparator (lambda function)
        // - If frequencies are equal, sort by value in descending order
        // - Otherwise, sort by frequency in ascending order
        // Time: O(n log n) — sorting the array
        // Space: O(1) — in-place sort (excluding freq map)
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if (freq[a] == freq[b])
                return a > b; // Higher value first if frequency is same
            return freq[a] < freq[b]; // Lower frequency first
        });

        // Total Time Complexity: O(n log n)
        // Total Space Complexity: O(n) — due to frequency map

        return nums;
    }
};

// 🧪 Main function for testing
int main() {
    Solution sol;
    vector<int> nums = {4, 5, 6, 5, 4, 3};

    vector<int> sorted = sol.frequencySort(nums);

    cout << "Sorted by frequency and value:\n";
    for (int num : sorted) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}