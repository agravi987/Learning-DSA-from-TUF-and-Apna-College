class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> st;  // Create an empty set to store unique elements

        // Iterate through each number in the array
        for(int num : nums) {
            // If the number already exists in the set, it's a duplicate
            if(st.find(num) != st.end()) {
                return true; // Duplicate found, return true
            }

            // Otherwise, insert the number into the set
            st.insert(num);
        }

        // If no duplicates were found, return false
        return false;
    }
};
