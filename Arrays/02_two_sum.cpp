#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// 🧪 Utility function to print result
void printResult(const vector<int>& result) {
    if (result.empty()) {
        cout << "No valid pair found.\n";
    } else {
        cout << "Indices: [" << result[0] << ", " << result[1] << "]\n";
    }
}

// 🚀 Brute Force Approach
// Time: O(n^2), Space: O(1)
class BruteForceSolution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {}; // No pair found
    }
};

// ⚡ Hash Map Approach (Optimal for Unsorted Arrays)
// Time: O(n), Space: O(n)
class HashMapSolution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; // value → index
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            auto it = mp.find(complement);
            if (it != mp.end()) {
                return {it->second, i};
            }
            mp[nums[i]] = i;
        }
        return {}; // No pair found
    }
};

// 🧭 Two Pointer Approach (Only for Sorted Arrays)
// Time: O(n), Space: O(1)
class TwoPointerSolution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == target) {
                return {left, right};
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return {}; // No pair found
    }
};

// 🧪 Main Function to Test All Approaches
int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    cout << "🔍 Testing Two Sum Approaches\n";

    // Brute Force
    {
        cout << "\nBrute Force:\n";
        BruteForceSolution brute;
        printResult(brute.twoSum(nums, target));
    }

    // Hash Map
    {
        cout << "\nHash Map:\n";
        HashMapSolution hashMap;
        printResult(hashMap.twoSum(nums, target));
    }

    // Two Pointer (requires sorted array)
    {
        cout << "\nTwo Pointer (Sorted Array):\n";
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end()); // Ensure sorted
        TwoPointerSolution twoPointer;
        printResult(twoPointer.twoSum(sortedNums, target));
    }

    return 0;
}