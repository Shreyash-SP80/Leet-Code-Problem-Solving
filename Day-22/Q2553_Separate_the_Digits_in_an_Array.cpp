#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
2553. Separate the Digits in an Array
--------------------------------------
Given an array of positive integers nums, return an array `answer` 
that consists of the digits of each integer in nums after separating them 
in the same order they appear in nums.

Example 1:
Input: nums = [13,25,83,77]
Output: [1,3,2,5,8,3,7,7]
Explanation:
- 13 -> [1,3]
- 25 -> [2,5]
- 83 -> [8,3]
- 77 -> [7,7]
Final answer = [1,3,2,5,8,3,7,7].

Example 2:
Input: nums = [7,1,3,9]
Output: [7,1,3,9]
Explanation:
Each number is a single digit.

--------------------------------------
# Approach:
- For each number in nums:
  - Convert it to string using `to_string(num)`.
  - Extract each character and push it as a digit (`c - '0'`).
- Append digits into `answer`.

# Complexity:
- Let n = size of nums, and k = total number of digits in all numbers.
- Time Complexity: O(k)  (we process each digit once).
- Space Complexity: O(k) (result array).
*/



class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> answer;
        for (int num : nums) {
            string s = to_string(num);
            for (char c : s) {
                answer.push_back(c - '0');
            }
        }
        return answer;
    }
};

// Driver code
int main() {
    Solution sol;

    vector<int> nums1 = {13, 25, 83, 77};
    auto res1 = sol.separateDigits(nums1);
    cout << "Output 1: ";
    for (int x : res1) cout << x << " ";
    cout << endl;

    vector<int> nums2 = {7, 1, 3, 9};
    auto res2 = sol.separateDigits(nums2);
    cout << "Output 2: ";
    for (int x : res2) cout << x << " ";
    cout << endl;

    return 0;
}
