#include <iostream>
#include <vector>
#include <queue>  // for priority_queue
using namespace std;

class Solution {
public:
    // Function to find k closest points to the origin (0,0)
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Max-heap that stores pairs (distance, point)
        // We use max-heap so that the farthest point among the current k points
        // is always on top and can be removed easily if we exceed k.
        priority_queue<pair<int, vector<int>>> maxHeap;
        vector<vector<int>> ans;

        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];

            // Calculate squared distance from origin to avoid sqrt (faster)
            int distance = x * x + y * y;

            // Push the current point with its distance
            maxHeap.push({distance, points[i]});

            // If heap size exceeds k, remove the farthest point
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        // Extract remaining k points from the heap
        while (!maxHeap.empty()) {
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return ans;
    }
};

// ---------------- MAIN FUNCTION -----------------
int main() {
    Solution sol;

    // Example input
    vector<vector<int>> points = {{3,3},{5,-1},{-2,4},{0,1}};
    int k = 2;

    // Get result
    vector<vector<int>> result = sol.kClosest(points, k);

    // Print result
    cout << k << " closest points to origin are: \n";
    for (auto &p : result) {
        cout << "[" << p[0] << ", " << p[1] << "]\n";
    }

    return 0;
}

/*
---------------- COMPLEXITY ANALYSIS ----------------
- Let n = number of points, k = number of closest points required.

1. Inserting into heap: O(log k) each
   → For n points, total = O(n log k)

2. Extracting k points: O(k log k)

Overall Time Complexity = O(n log k)

Space Complexity = O(k) (heap stores at most k points)
*/
