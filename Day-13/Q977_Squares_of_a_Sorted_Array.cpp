#include <iostream>
#include <vector>
#include <cmath>    // for pow() and abs()
#include <algorithm> // for sort()


/*
Problem: 977. Squares of a Sorted Array
---------------------------------------
Given an integer array `nums` sorted in non-decreasing order, 
return an array of the squares of each number sorted in non-decreasing order.

Example 1:
----------
Input: nums = [-4, -1, 0, 3, 10]
Output: [0, 1, 9, 16, 100]
Explanation:
    After squaring: [16, 1, 0, 9, 100]
    After sorting:  [0, 1, 9, 16, 100]

Example 2:
----------
Input: nums = [-7, -3, 2, 3, 11]
Output: [4, 9, 9, 49, 121]

Constraints:
------------
- 1 <= nums.length <= 10^4
- -10^4 <= nums[i] <= 10^4
- nums is sorted in non-decreasing order.

-----------------------------------------------------------------------
Approach:
---------
1. Since the array is sorted, but contains negative numbers, squaring 
   them may disrupt the order.
2. We can simply square each element, then sort the array again.
3. Time Complexity:
    - Squaring: O(n)
    - Sorting:  O(n log n)
   Total: O(n log n)
4. Space Complexity: O(1) (in-place modification)
-----------------------------------------------------------------------
*/



using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Square each element
        for (int i = 0; i < n; i++) {
            nums[i] = pow(nums[i], 2); // square directly
        }

        // Step 2: Sort the squared values
        sort(nums.begin(), nums.end());

        return nums; // return sorted squared array
    }
};

int main() {
    // Input array
    vector<int> nums = {-4, -1, 0, 3, 10};

    Solution obj;
    vector<int> result = obj.sortedSquares(nums);

    // Output the result
    cout << "Sorted Squares: ";
    for (int val : result) {
        cout << val << " "; 
    }
    cout << endl;
    // Sorted Squares: 0 1 9 16 99 

    return 0;
}
