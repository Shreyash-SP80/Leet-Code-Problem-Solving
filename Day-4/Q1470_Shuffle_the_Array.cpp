#include <iostream>
#include <vector>
using namespace std;

/*
    LeetCode Problem 1470 - Shuffle the Array
    Link: https://leetcode.com/problems/shuffle-the-array/

    ------------------------------------------
    🧠 Problem Statement:
    Given an array 'nums' consisting of 2n elements in the form:
    [x1, x2, ..., xn, y1, y2, ..., yn]

    Return the array in the form:
    [x1, y1, x2, y2, ..., xn, yn]

    ------------------------------------------
    🔢 Example 1:
    Input: nums = [2,5,1,3,4,7], n = 3
    Output: [2,3,5,4,1,7]

    🔢 Example 2:
    Input: nums = [1,2,3,4,4,3,2,1], n = 4
    Output: [1,4,2,3,3,2,4,1]

    🔢 Example 3:
    Input: nums = [1,1,2,2], n = 2
    Output: [1,2,1,2]

    ------------------------------------------
    ✅ Approach:
    - Given nums of size 2n, we separate it into two halves:
      First half:   nums[0] to nums[n-1]    -> x1, x2, ..., xn
      Second half:  nums[n] to nums[2n - 1] -> y1, y2, ..., yn

    - We iterate from 0 to n-1:
        1. Push nums[i]   (xi)
        2. Push nums[i+n] (yi)
    
    - Result is built by alternately picking from both halves.

    🕒 Time Complexity: O(n)
    🧠 Space Complexity: O(n)  (for result array)
*/

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> result;

        // Traverse from 0 to n-1 and pair xi and yi
        for (int i = 0; i < n; i++) {
            result.push_back(nums[i]);       // x1, x2, ..., xn
            result.push_back(nums[i + n]);   // y1, y2, ..., yn
        }

        return result;
    }
};

// Helper function to print vector
void printVector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i != vec.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    Solution obj;

    // Test Case 1
    vector<int> nums1 = {2, 5, 1, 3, 4, 7};
    int n1 = 3;
    vector<int> result1 = obj.shuffle(nums1, n1);
    cout << "Test Case 1 Output: ";
    printVector(result1);

    // Test Case 2
    vector<int> nums2 = {1, 2, 3, 4, 4, 3, 2, 1};
    int n2 = 4;
    vector<int> result2 = obj.shuffle(nums2, n2);
    cout << "Test Case 2 Output: ";
    printVector(result2);

    // Test Case 3
    vector<int> nums3 = {1, 1, 2, 2};
    int n3 = 2;
    vector<int> result3 = obj.shuffle(nums3, n3);
    cout << "Test Case 3 Output: ";
    printVector(result3);

    return 0;
}
