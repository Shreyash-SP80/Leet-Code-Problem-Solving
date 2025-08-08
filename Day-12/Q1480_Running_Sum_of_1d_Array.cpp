#include <iostream>
#include<vector>
using namespace std;

/*
----------------------------------------
Problem: 1480. Running Sum of 1d Array
----------------------------------------
Given an array nums, return the running sum of nums.
The running sum is defined as:
runningSum[i] = sum(nums[0] ... nums[i])

----------------------------------------
Example 1:
Input: nums = [1, 2, 3, 4]
Output: [1, 3, 6, 10]
Explanation: [1, (1+2), (1+2+3), (1+2+3+4)]

Example 2:
Input: nums = [1, 1, 1, 1, 1]
Output: [1, 2, 3, 4, 5]
Explanation: cumulative sum increases by 1 each time.

Example 3:
Input: nums = [3, 1, 2, 10, 1]
Output: [3, 4, 6, 16, 17]
----------------------------------------

Approach:
1. Create a result vector of same size as nums.
2. Set the first element of result equal to nums[0].
3. For each index i from 1 to n-1:
     - result[i] = result[i-1] + nums[i]
   This way we accumulate sums without recomputing from start each time.
4. Return result vector.

Time Complexity: O(n) — single pass over the array.
Space Complexity: O(n) for result array (O(1) if done in-place).
----------------------------------------
*/

vector<int> runningSum(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n);

    result[0] = nums[0]; // First element stays same
    for (int i = 1; i < n; i++) {
        result[i] = result[i - 1] + nums[i]; // Add previous sum to current number
    }

    // OR

    // for (int i = 0; i < n; i++) {
    //     result[i] = accumulate(nums.begin(), nums.begin()+i+1, 0);
    // }
    return result;
}

int main() {
    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> nums2 = {1, 1, 1, 1, 1};
    vector<int> nums3 = {3, 1, 2, 10, 1};

    auto printVector = [](const vector<int>& v) {
        for (int num : v) cout << num << " ";
        cout << endl;
    };

    cout << "Test case 1: ";
    printVector(runningSum(nums1));

    cout << "Test case 2: ";
    printVector(runningSum(nums2));

    cout << "Test case 3: ";
    printVector(runningSum(nums3));

    return 0;
}

/*
Expected Output:
Test case 1: 1 3 6 10
Test case 2: 1 2 3 4 5
Test case 3: 3 4 6 16 17
*/
