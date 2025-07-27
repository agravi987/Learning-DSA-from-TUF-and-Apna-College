#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to find the peak index in a mountain array
    int peakIndexInMountainArray(vector<int>& arr) {
        int st = 1; // Start from index 1 (since index 0 can't be a peak)
        int end = arr.size() - 2; // End at second-to-last index

        while (st <= end) {
            int mid = st + (end - st) / 2;

            // Check if arr[mid] is the peak element
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
                return mid;
            }
            // If the slope is going up, move right
            else if (arr[mid - 1] <= arr[mid]) {
                st = mid + 1;
            }
            // If the slope is going down, move left
            else {
                end = mid - 1;
            }
        }

        // If no peak is found (shouldn't happen for a valid mountain array)
        return -1;
    }
};

int main() {
    Solution sol;

    // Example mountain array
    vector<int> mountain = {1, 3, 5, 7, 6, 4, 2};

    // Call the function and print the result
    int peakIndex = sol.peakIndexInMountainArray(mountain);
    cout << "Peak index is: " << peakIndex << endl;
    cout << "Peak element is: " << mountain[peakIndex] << endl;

    return 0;
}