#include <iostream>
#include <vector>
using namespace std;

/*
    🔶 PROBLEM STATEMENT:
    You are given two sorted integer arrays nums1 and nums2, and two integers m and n, 
    representing the number of valid elements in nums1 and nums2 respectively.

    nums1 has a size of m + n, where the last n elements are set to 0 (placeholders).
    Merge nums2 into nums1 in sorted order, in-place if possible.

    Example:
    Input: nums1 = [1,2,3,0,0,0], m = 3
           nums2 = [2,5,6],       n = 3
    Output: [1,2,2,3,5,6]
*/

/* --------------------------------------------
   🔹 BRUTE FORCE APPROACH (Uses Extra Space)
   Time Complexity: O(m + n)
   Space Complexity: O(m + n)
--------------------------------------------- */
class SolutionBruteForce {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;
        int i = 0, j = 0;

        // Merge both arrays in sorted order
        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) 
                ans.push_back(nums1[i++]);
            else 
                ans.push_back(nums2[j++]);
        }

        // Append remaining elements from nums1 (if any)
        while (i < m) 
            ans.push_back(nums1[i++]);

        // Append remaining elements from nums2 (if any)
        while (j < n) 
            ans.push_back(nums2[j++]);

        // Copy merged result back to nums1
        for (int idx = 0; idx < m + n; idx++) {
            nums1[idx] = ans[idx];
        }
    }
};

/* --------------------------------------------
   🔹 OPTIMAL IN-PLACE APPROACH (No Extra Space)
   Time Complexity: O(m + n)
   Space Complexity: O(1)
--------------------------------------------- */
class SolutionOptimal {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;          // Last valid element in nums1
        int j = n - 1;          // Last element in nums2
        int idx = m + n - 1;    // Last index of nums1 (total space)

        // Fill nums1 from the end to avoid overwriting
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) 
                nums1[idx--] = nums1[i--];
            else 
                nums1[idx--] = nums2[j--];
        }

        // Copy remaining elements from nums2 (if any)
        while (j >= 0) 
            nums1[idx--] = nums2[j--];

        // No need to copy nums1's remaining elements—they're already in place
    }
};

// Main function to test both implementations
int main() {
    vector<int> nums1a = {1, 2, 3, 0, 0, 0};
    vector<int> nums2a = {2, 5, 6};
    int m = 3, n = 3;

    vector<int> nums1b = nums1a; // Copy for second test

    SolutionBruteForce brute;
    brute.merge(nums1a, m, nums2a, n);

    cout << "Merged using Brute Force: ";
    for (int num : nums1a) cout << num << " ";
    cout << endl;

    SolutionOptimal optimal;
    optimal.merge(nums1b, m, nums2a, n);

    cout << "Merged using Optimal (In-place): ";
    for (int num : nums1b) cout << num << " ";
    cout << endl;

    return 0;
}
