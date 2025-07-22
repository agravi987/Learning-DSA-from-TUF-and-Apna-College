class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int targetIndex = nums.size() - k; 
        return quickSelect(nums, 0, nums.size() - 1, targetIndex); 
    }

    int quickSelect(vector<int>& nums, int left, int right, int k) {
        if (left <= right) {
            int pivot = partition(nums, left, right); 

            if (pivot == k) {
                return nums[pivot]; 
            } else if (pivot < k) {
                return quickSelect(nums, pivot + 1, right, k); 
            } else {
                return quickSelect(nums, left, pivot - 1, k); 
            }
        }
        return -1; // for invalid case
    }

    int partition(vector<int>& nums, int left, int right) {
        int idx = left - 1; 
        int pivot = nums[right]; 

        for (int j = left; j < right; j++) {
            if (nums[j] < pivot) {
                idx++; 
                swap(nums, idx, j); 
            }
        }

        idx++; 
        swap(nums, idx, right); 

        return idx; 
    }

    void swap(vector<int>& nums, int a, int b) {
        int temp = nums[a]; 
        nums[a] = nums[b]; 
        nums[b] = temp; 
    }
};
