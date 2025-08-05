#include <iostream>
#include <vector>
using namespace std;

/*
905. Sort Array By Parity
--------------------------

Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.

Return any array that satisfies this condition.

Example 1:
Input:  nums = [3,1,2,4]
Output: [2,4,3,1]

Example 2:
Input:  nums = [0]
Output: [0]

Constraints:
- 1 <= nums.length <= 5000
- 0 <= nums[i] <= 5000
*/

/*
Approach:
---------
1. Create a new vector `result` of the same size as input `nums`.
2. Use a pointer `j` to track the insertion position.
3. First, insert all even elements into `result`.
4. Then, insert all odd elements.
5. Return the result vector.


Source Link: https://leetcode.com/problems/sort-array-by-parity/

*/

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int j = 0;

        // Insert even numbers first
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) {
                result[j++] = nums[i];
            }
        }

        // Then insert odd numbers
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 != 0) {
                result[j++] = nums[i];
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    
    vector<int> nums = {3, 1, 2, 4};
    vector<int> sorted = sol.sortArrayByParity(nums);

    cout << "Sorted array by parity: ";
    for (int num : sorted) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
