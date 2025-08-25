#include <iostream>
#include <vector>
using namespace std;

/*
1389. Create Target Array in the Given Order
---------------------------------------------
You are given two arrays of integers nums and index. 
Your task is to create a target array under the following rules:

1. Initially target array is empty.
2. From left to right, read nums[i] and index[i],
   then insert at index[i] the value nums[i] in the target array.
3. Repeat this until all elements are processed.

It is guaranteed that all insertions are valid.

Example 1:
Input: nums = [0,1,2,3,4], index = [0,1,2,2,1]
Output: [0,4,1,3,2]
Explanation:
nums   index   target
0       0      [0]
1       1      [0,1]
2       2      [0,1,2]
3       2      [0,1,3,2]
4       1      [0,4,1,3,2]

Example 2:
Input: nums = [1,2,3,4,0], index = [0,1,2,3,0]
Output: [0,1,2,3,4]

Example 3:
Input: nums = [1], index = [0]
Output: [1]
*/

/*
# Intuition
We just need to simulate the process:
- Iterate over nums and index.
- For each i, insert nums[i] into target at position index[i].

# Approach
- Use a vector `target`.
- Use `target.insert(target.begin() + index[i], nums[i])` for each step.

# Complexity
- Each `insert` in a vector is O(n) in the worst case (because elements may shift).
- Since we do n insertions, total complexity = O(n^2).
- This is acceptable because constraints are small (n ≤ 100).

# Note
For larger constraints, we could consider data structures like 
`std::list` or `Fenwick Tree` (BIT) to reduce insertion cost.
*/


class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> target;
        for (int i = 0; i < nums.size(); i++) {
            target.insert(target.begin() + index[i], nums[i]);
        }
        return target;
    }
};

// Driver code
int main() {
    Solution sol;

    vector<int> nums1 = {0,1,2,3,4};
    vector<int> idx1  = {0,1,2,2,1};
    auto res1 = sol.createTargetArray(nums1, idx1);
    cout << "Output 1: ";
    for (int x : res1) cout << x << " ";
    cout << endl;

    vector<int> nums2 = {1,2,3,4,0};
    vector<int> idx2  = {0,1,2,3,0};
    auto res2 = sol.createTargetArray(nums2, idx2);
    cout << "Output 2: ";
    for (int x : res2) cout << x << " ";
    cout << endl;

    vector<int> nums3 = {1};
    vector<int> idx3  = {0};
    auto res3 = sol.createTargetArray(nums3, idx3);
    cout << "Output 3: ";
    for (int x : res3) cout << x << " ";
    cout << endl;

    return 0;
}
