#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

class Solution {
public:
    /*
     * Function to find the top k frequent elements in the array.
     *
     * Time Complexity:
     * - Counting frequencies: O(n), where n is the size of nums
     * - Building the heap: O(m log k), where m is the number of unique elements
     *   (each insertion into min-heap takes O(log k), and we do this m times)
     * - Extracting k elements: O(k)
     * - Total: O(n + m log k), and since m ≤ n, it's O(n log k)
     *
     * Space Complexity:
     * - O(n) for frequency map
     * - O(k) for the heap and result vector
     */
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp; // Frequency map: element -> count

        // Count frequencies of each number
        for (int num : nums) {
            mp[num]++;
        }

        // Min-heap to keep top k frequent elements
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        // Push frequency-element pairs into heap
        for (auto& pair : mp) {
            minHeap.push({pair.second, pair.first});

            // Maintain heap size ≤ k
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        // Extract top k frequent elements from heap
        vector<int> ans;
        while (!minHeap.empty()) {
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return ans;
    }
};