class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int low = 0; 
            int high = nums.size() - 1;
    
            // ✅ Fix: Use <= to ensure we check all elements including the last one
            while (low <= high) {
                int mid = low + (high - low) / 2;
    
                // If the middle element is the target, return its index
                if (nums[mid] == target) {
                    return mid;
                }
    
                // Left half is sorted
                if (nums[low] <= nums[mid]) {
                    // Target is in the left sorted part
                    if (nums[low] <= target && target < nums[mid])
                        high = mid - 1;
                    else
                        low = mid + 1;
                } 
                // Right half is sorted
                else {
                    // Target is in the right sorted part
                    if (nums[mid] < target && target <= nums[high])
                        low = mid + 1;
                    else
                        high = mid - 1;
                }
            }
    
            // Target not found
            return -1;
        }
    };
    