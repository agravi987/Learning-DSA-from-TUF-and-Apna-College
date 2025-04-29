// LeetCode - Problem 121: Best Time to Buy and Sell Stock

// Brute Force Approach
// Time Complexity: O(n^2) - Check every possible pair of days to find the maximum profit.
// Space Complexity: O(1)
class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int n = prices.size();
            int maxProfit = 0;
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    // Calculate profit by selling on day j after buying on day i
                    int profit = prices[j] - prices[i];
                    maxProfit = max(maxProfit, profit); // Update maxProfit if current profit is greater
                }
            }
            return maxProfit; // Return the maximum profit
        }
    };
    
    // Optimal Approach
    // Time Complexity: O(n) - Traverse the array once.
    // Space Complexity: O(1) - No extra space is used.
    class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int minPrice = INT_MAX; // Initialize to a large value
            int maxProfit = 0; // Maximum profit starts at 0
            for (int i = 0; i < prices.size(); i++) {
                // Update minPrice to the lowest price encountered so far
                minPrice = min(minPrice, prices[i]);
                // Calculate profit for the current price and update maxProfit if higher
                maxProfit = max(maxProfit, prices[i] - minPrice);
            }
            return maxProfit; // Return the maximum profit
        }
    };