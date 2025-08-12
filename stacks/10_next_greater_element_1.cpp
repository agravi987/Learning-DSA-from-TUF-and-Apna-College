#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

/*
Problem:
For each element in nums1, find the next greater element in nums2.
nums1 is a subset of nums2.

Approach:
- Use a stack to find the next greater element (NGE) for all elements in nums2.
- Store the NGE in a hashmap (unordered_map).
- Iterate over nums1 and use the hashmap to get the result.

Time Complexity: O(n + m), where n = nums2.size(), m = nums1.size()
Space Complexity: O(n) for stack and map
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nge;   // stores element -> next greater element
        stack<int> st;                 // monotonic decreasing stack

        int n = nums2.size();

        // Traverse nums2 from end to start
        for (int i = n - 1; i >= 0; i--) {
            // Maintain a decreasing stack (pop smaller or equal elements)
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            // If stack is empty, no greater element to the right
            if (st.empty()) {
                nge[nums2[i]] = -1;
            } else {
                nge[nums2[i]] = st.top();
            }

            // Push current element into stack
            st.push(nums2[i]);
        }

        // Build result for nums1 using the map
        vector<int> ans;
        for (int num : nums1) {
            ans.push_back(nge[num]);
        }

        return ans;
    }
};

/* ------------------------ MAIN FUNCTION ------------------------ */
int main() {
    // Sample Input
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    // Create Solution object and call method
    Solution sol;
    vector<int> result = sol.nextGreaterElement(nums1, nums2);

    // Output the result
    cout << "Next Greater Elements:\n";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
