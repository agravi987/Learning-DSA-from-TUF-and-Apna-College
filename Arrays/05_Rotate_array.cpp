// brute force 

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // Handle cases where k > n

        vector<int> temp;

        // Step 1: Copy last k elements to temp
        for(int i = n - k; i < n; i++) {
            temp.push_back(nums[i]);
        }

        // Step 2: Copy first n-k elements to temp
        for(int i = 0; i < n - k; i++) {
            temp.push_back(nums[i]);
        }

        // Step 3: Copy back temp to original nums
        for(int i = 0; i < n; i++) {
            nums[i] = temp[i];
        }
    }
};


// optimized approach 

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size(); 
        
        // Handle cases where k > n
        k = k % n;  

        // Step 1: Reverse the entire array
        reverse(nums.begin(), nums.end());  
        // Example: [1,2,3,4,5,6,7] → [7,6,5,4,3,2,1]

        // Step 2: Reverse the first k elements
        reverse(nums.begin(), nums.begin() + k);  
        // Example: [7,6,5,4,3,2,1] → [5,6,7,4,3,2,1] (if k=3)

        // Step 3: Reverse the remaining n-k elements
        reverse(nums.begin() + k, nums.end());    
        // Example: [5,6,7,4,3,2,1] → [5,6,7,1,2,3,4]
    }
};
