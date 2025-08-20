#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to search target in a rotated sorted array
    int search(vector<int>& nums, int target) {
        int low = 0; 
        int high = nums.size() - 1;

        // Binary Search (modified for rotated sorted array)
        while (low <= high) {
            int mid = low + (high - low) / 2;  // avoid overflow

            // ✅ Case 1: Found the target
            if (nums[mid] == target) {
                return mid;
            }

            // ✅ Case 2: Left half is sorted
            if (nums[low] <= nums[mid]) {
                // Check if target lies in this left half
                if (nums[low] <= target && target < nums[mid])
                    high = mid - 1;  // shrink search space to left half
                else
                    low = mid + 1;   // otherwise search in right half
            } 
            // ✅ Case 3: Right half is sorted
            else {
                // Check if target lies in this right half
                if (nums[mid] < target && target <= nums[high])
                    low = mid + 1;   // shrink search space to right half
                else
                    high = mid - 1;  // otherwise search in left half
            }
        }

        // If target not found, return -1
        return -1;
    }
};

// ---------------- MAIN FUNCTION -----------------
int main() {
    Solution sol;

    // Example rotated sorted array
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;

    int index = sol.search(nums, target);

    if (index != -1)
        cout << "Target " << target << " found at index: " << index << endl;
    else
        cout << "Target " << target << " not found in array." << endl;

    return 0;
}

/*
------------------- EXPLANATION -------------------

We are searching in a Rotated Sorted Array:
Example: nums = [4,5,6,7,0,1,2], target = 0

1. Normally binary search works only on sorted arrays.
   But here the array is rotated at some pivot.

2. At every step:
   - Find mid = (low + high) / 2
   - Check if nums[mid] == target (direct match)
   - Otherwise, one half (left or right) will always be sorted.

3. Decide where to search next:
   - If left half is sorted:
       check if target lies in [nums[low], nums[mid-1]]
       else move to right half.
   - If right half is sorted:
       check if target lies in [nums[mid+1], nums[high]]
       else move to left half.

4. Keep repeating until low > high (target not found).

------------------- COMPLEXITY -------------------

✅ Time Complexity: O(log N)  
   - Each step reduces search space by half (binary search style).  

✅ Space Complexity: O(1)  
   - Only using a few variables, no extra data structures.  

---------------------------------------------------
*/
