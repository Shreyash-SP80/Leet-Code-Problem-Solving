#include <iostream>
#include <vector>
using namespace std;


/*
Leetcode 565. Array Nesting
---------------------------

📝 Problem Statement:
You are given an integer array `nums` of length `n` where `nums` is a **permutation** of the numbers in the range `[0, n - 1]`.

You should build a set `s[k] = {nums[k], nums[nums[k]], nums[nums[nums[k]]], ... }` subjected to the following rule:

- The first element in `s[k]` starts with the selection of `nums[k]` at index `k`.
- The next element should be `nums[nums[k]]`, then `nums[nums[nums[k]]]`, and so on.
- We stop adding right before a duplicate element occurs in `s[k]`.

🔧 Task:
Return the **longest length** of a set `s[k]` over all `k` in the array.

🧪 Examples:

Example 1:
Input:  nums = [5,4,0,3,1,6,2]
Output: 4
Explanation: 
One of the longest sets `s[k]` is:
s[0] = {nums[0], nums[5], nums[6], nums[2]} = {5, 6, 2, 0}

Example 2:
Input:  nums = [0,1,2]
Output: 1
*/



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


