// LeetCode - Problem 1: Two Sum

// Brute Force Solution
// Time Complexity: O(n^2) - For each number, iterate over the rest to find the complement.
// Space Complexity: O(1)
class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            int n = nums.size();
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (nums[i] + nums[j] == target) {
                        return {i, j};
                    }
                }
            }
            return {}; // Return empty if no pair is found
        }
    };
    
    // Better Approach
    // Use a map (or unordered_map) to store complements.
    // Time Complexity: O(n) - Traverse the array and use map operations (O(1) average case).
    // Space Complexity: O(n) - To store the elements in the map.
    class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int> mp; // Use unordered_map for better performance
            for (int i = 0; i < nums.size(); i++) {
                int complement = target - nums[i]; // Complement to look for
                if (mp.find(complement) != mp.end()) { // Check if the complement exists
                    return {mp[complement], i}; // Return indices of the numbers
                }
                mp[nums[i]] = i; // Store the current number with its index
            }
            return {}; // Return empty if no pair is found
        }
    };
    
    // Optimal Approach (Two-Pointer Technique - Only Applicable for Sorted Array)
    // Time Complexity: O(n) - Traverse the array with two pointers.
    // Space Complexity: O(1)
    class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            int left = 0, right = nums.size() - 1;
            // Assuming the input array is sorted
            while (left < right) {
                int sum = nums[left] + nums[right];
                if (sum == target) {
                    return {left, right}; // Indices of the two numbers
                } else if (sum < target) {
                    left++; // Increment left pointer to increase sum
                } else {
                    right--; // Decrement right pointer to decrease sum
                }
            }
            return {}; // Return empty if no pair is found
        }
    };