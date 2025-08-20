#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Find floor of x in a sorted array
    // Floor = greatest element <= x
    int findFloor(vector<int>& arr, int x) {
        int n = arr.size();
        int low = 0, high = n - 1;
        int ans = -1;  // store index of floor

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] <= x) {
                ans = mid;      // candidate floor
                low = mid + 1;  // but maybe there's a bigger one → go right
            } else {
                high = mid - 1; // arr[mid] > x → go left
            }
        }
        return ans; // -1 if no floor exists
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 4, 6, 10, 12, 14};
    int x = 5;

    int idx = sol.findFloor(arr, x);
    if (idx != -1)
        cout << "Floor of " << x << " is " << arr[idx] 
             << " at index " << idx << endl;
    else
        cout << "No floor exists for " << x << endl;

    return 0;
}

/*
⚡ Quick Notes:
- Floor(x): greatest element <= x
- Use Binary Search:
    • If arr[mid] <= x → store it (possible floor), move right
    • If arr[mid] > x  → move left
- Finally 'ans' holds index of floor, or -1 if not found.

Example: arr = [1,2,4,6,10], x = 5
Steps:
   mid=2 → arr[2]=4 ≤ 5 → ans=2, move right
   mid=3 → arr[3]=6 > 5 → move left
   end → ans=2 → floor=4

✅ TC: O(log N), SC: O(1)
*/
