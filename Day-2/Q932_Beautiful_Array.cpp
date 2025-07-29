#include <iostream>
#include <vector>

using namespace std;


/*
LeetCode Problem 932: Beautiful Array
-------------------------------------

An array nums of length n is called beautiful if:

1. nums is a permutation of the integers in the range [1, n].
2. For every 0 <= i < j < n, there is no index k with i < k < j such that:
       2 * nums[k] == nums[i] + nums[j]
   (i.e., no element between nums[i] and nums[j] is the average of those two)

Your task:
----------
Given an integer n, return any beautiful array nums of length n.
There will always be at least one valid answer for any n.

Input:
------
- An integer n (1 ≤ n ≤ 1000)

Output:
-------
- A vector containing a beautiful array of length n.

Examples:
---------
Input: n = 4
Output: [2, 1, 4, 3]

Input: n = 5
Output: [3, 1, 2, 5, 4]

Note:
-----
- Multiple correct answers are allowed.
- The result must be a permutation of numbers from 1 to n.
- The array must not contain any arithmetic triplet: 
  nums[i], nums[k], nums[j] such that i < k < j and 2 * nums[k] == nums[i] + nums[j]
*/



/*
Approach:
---------
The idea is to construct a beautiful array using a divide and conquer method.

Key Observations:
1. A beautiful array has no arithmetic triplet (i < k < j such that 2 * A[k] == A[i] + A[j]).
2. To avoid such triplets, we divide the problem into two:
   - Odd indexed elements: 2 * x - 1
   - Even indexed elements: 2 * x
3. Starting from base case [1], we expand the array at each step by:
   - Generating all odd elements from current array: 2*x - 1
   - Generating all even elements from current array: 2*x
   - Keep only values ≤ n
4. This preserves the beautiful property recursively.
*/



class Solution {
public:
    vector<int> beautifulArray(int n) {
        // Start with the base case
        vector<int> result = {1};

        // Keep building until we have 'n' elements
        while (result.size() < n) {
            vector<int> temp;

            // Generate odd numbers (2x - 1)
            for (int x : result) {
                if (2 * x - 1 <= n) {
                    temp.push_back(2 * x - 1);
                }
            }

            // Generate even numbers (2x)
            for (int x : result) {
                if (2 * x <= n) {
                    temp.push_back(2 * x);
                }
            }

            // Update the result with newly built temp
            result = temp;
        }

        return result;
    }
};

int main() {
    Solution sol;
    int n = 4;  // Example input

    vector<int> beautiful = sol.beautifulArray(n);

    cout << "Beautiful Array for n = " << n << ": ";
    for (int num : beautiful) {
        cout << num << " ";
    }
    cout << endl;
    // Beautiful Array for n = 4: 1 3 2 4
    return 0;
}
