#include <iostream>
#include <vector>
using namespace std;


/*
1979. Find Greatest Common Divisor of Array
-------------------------------------------
Given an integer array `nums`, return the greatest common divisor (GCD) 
of the smallest number and largest number in `nums`.

The GCD of two numbers is the largest positive integer that evenly divides both numbers.

Example 1:
Input: nums = [2,5,6,9,10]
Output: 2
Explanation: smallest = 2, largest = 10, GCD(2,10) = 2

Example 2:
Input: nums = [7,5,6,8,3]
Output: 1
Explanation: smallest = 3, largest = 8, GCD(3,8) = 1
*/

/*
# Intuition
- We only need GCD of min and max of the array.
- Use Euclidean algorithm to calculate GCD.

# Approach
1. Initialize `smallest` and `greatest` with first element.
2. Loop through array to find actual smallest and greatest.
3. Apply Euclidean algorithm:
   - while greatest != 0:
       temp = greatest
       greatest = smallest % greatest
       smallest = temp
4. Return smallest (GCD).

# Complexity
- Time: O(n + log(max-min)), n = size of nums
- Space: O(1)
*/


class Solution {
public:
    int findGCD(vector<int>& nums) {
        int smallest = nums[0], greatest = nums[0];

        for (int num : nums) {
            if (num < smallest) smallest = num;
            if (num > greatest) greatest = num;
        }

        // Euclidean algorithm
        while (greatest != 0) {
            int temp = greatest;
            greatest = smallest % greatest;
            smallest = temp;
        }

        return smallest;
    }
};

// Driver code
int main() {
    Solution sol;

    vector<int> nums1 = {2,5,6,9,10};
    cout << "Output 1: " << sol.findGCD(nums1) << endl; // 2

    vector<int> nums2 = {7,5,6,8,3};
    cout << "Output 2: " << sol.findGCD(nums2) << endl; // 1

    vector<int> nums3 = {3,3};
    cout << "Output 3: " << sol.findGCD(nums3) << endl; // 3

    return 0;
}
