#include <iostream>
#include <vector>
#include <algorithm> // for min and max
using namespace std;

// 🧠 Brute Force Approach - Time Complexity: O(n^2)
class BruteForceSolution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;

        // Try every possible pair (i, j) where i < j
        for (int i = 0; i < height.size(); i++) {
            for (int j = i + 1; j < height.size(); j++) {
                // Find the shorter height between two lines
                int length = min(height[i], height[j]);
                // Width between the lines
                int breadth = j - i;
                // Calculate area and update maxArea if needed
                int currentArea = length * breadth;
                maxArea = max(maxArea, currentArea);
            }
        }

        return maxArea;
    }
};

// ⚡ Optimal Approach - Two Pointer Technique - Time Complexity: O(n)
class OptimalSolution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;

        while (left < right) {
            // Get the minimum height between the two pointers
            int ht = min(height[left], height[right]);
            // Calculate width between left and right
            int width = right - left;
            // Area formed by current left and right
            int currentArea = ht * width;
            maxArea = max(maxArea, currentArea);

            // Move the pointer pointing to the shorter line
            if (height[left] < height[right])
                left++;
            else
                right--;
        }

        return maxArea;
    }
};

int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};

    // Test Brute Force
    BruteForceSolution brute;
    cout << "Max Area (Brute Force): " << brute.maxArea(height) << endl;

    // Test Optimal Two-Pointer
    OptimalSolution optimal;
    cout << "Max Area (Optimal): " << optimal.maxArea(height) << endl;

    return 0;
}
