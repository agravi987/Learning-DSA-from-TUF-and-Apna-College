#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Approach 1: Brute Force
Time Complexity: O(n^2)
Space Complexity: O(1)
For each element, find the maximum on the left and right, and compute water trapped.
*/
class Solution1 {
public:
    int trap(vector<int>& height) {
        int n = height.size(); 
        int totalTappedWater = 0;

        for (int i = 1; i < n - 1; i++) {
            int maxLeft = 0, maxRight = 0;

            // Find max on the left
            for (int j = 0; j < i; j++) {
                maxLeft = max(maxLeft, height[j]);
            }

            // Find max on the right
            for (int j = i + 1; j < n; j++) {
                maxRight = max(maxRight, height[j]);
            }

            // Calculate trapped water at position i
            int waterAtI = min(maxRight, maxLeft) - height[i];
            if (waterAtI > 0) {
                totalTappedWater += waterAtI;
            }
        }

        return totalTappedWater;
    }
};

/*
Approach 2: Prefix Arrays (LeftMax and RightMax)
Time Complexity: O(n)
Space Complexity: O(n)
We precompute the max height to the left and right for each bar.
*/
class Solution2 {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        vector<int> leftMaxArr(n), rightMaxArr(n);
        int totalWater = 0;

        // Fill left max array
        leftMaxArr[0] = height[0];
        for (int i = 1; i < n; i++) {
            leftMaxArr[i] = max(leftMaxArr[i - 1], height[i]);
        }

        // Fill right max array
        rightMaxArr[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMaxArr[i] = max(rightMaxArr[i + 1], height[i]);
        }

        // Calculate water trapped at each index
        for (int i = 0; i < n; i++) {
            int waterAtI = min(leftMaxArr[i], rightMaxArr[i]) - height[i];
            if (waterAtI > 0) {
                totalWater += waterAtI;
            }
        }

        return totalWater;
    }
};

/*
Approach 3: Two Pointer (Most Optimal)
Time Complexity: O(n)
Space Complexity: O(1)
We use two pointers to move inward from both ends and track max height on both sides.
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;
        int totalWater = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                leftMax = max(leftMax, height[left]);
                totalWater += leftMax - height[left];
                left++;
            } else {
                rightMax = max(rightMax, height[right]);
                totalWater += rightMax - height[right];
                right--;
            }
        }

        return totalWater;
    }
};

/* --------------------------- MAIN FUNCTION --------------------------- */
int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

    // Testing all approaches
    Solution1 bruteForce;
    Solution2 prefixArray;
    Solution twoPointer;

    cout << "Brute Force Result: " << bruteForce.trap(height) << endl;
    cout << "Prefix Array Result: " << prefixArray.trap(height) << endl;
    cout << "Two Pointer Result (Optimal): " << twoPointer.trap(height) << endl;

    return 0;
}
