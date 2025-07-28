#include <iostream>
#include <vector>
using namespace std;

// Approach:
// ---------
// 1. Initialize a visited array to avoid processing the same cycle multiple times.
// 2. For each unvisited index 'i', traverse the nesting set s[i] = {nums[i], nums[nums[i]], ...}
// 3. Continue until a repeated (already visited) index is found (cycle ends).
// 4. Keep track of the size of each set and update maxCount if needed.
// 5. Return the maximum size found among all s[k].

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n, false); // Track which indices have been visited
        int maxCount = 0; // Store the maximum length of any set s[k]

        // Loop through each index as a potential starting point
        for (int i = 0; i < n; ++i) {
            // Only start exploring if this index hasn't been visited
            if (!visited[i]) {
                int start = i;
                int count = 0;

                // Traverse the set s[k] = {nums[k], nums[nums[k]], ...}
                while (!visited[start]) {
                    visited[start] = true;     // Mark current index as visited
                    start = nums[start];       // Move to the next index in the nesting
                    count++;                   // Increment the count for this chain
                }

                // Update maxCount if the current chain is the longest so far
                maxCount = max(maxCount, count);
            }
        }

        return maxCount; // Return the length of the longest nesting set
    }
};

int main() {
    Solution sol;

    // Sample input: permutation of numbers from 0 to 6
    vector<int> nums = {5, 4, 0, 3, 1, 6, 2};

    // Function call
    int result = sol.arrayNesting(nums);

    // Output the result
    cout << "The length of the longest nesting set is: " << result << endl;  // 4

    return 0;
}


