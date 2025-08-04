#include<iostream>
#include<vector>
using namespace std;

/*
🧠 Problem: 3637. Trionic Array I
Difficulty: Easy
Link: (LeetCode Premium)

🔸 Description:
You are given an integer array `nums` of length `n`.

An array is called **trionic** if there exist indices `0 < p < q < n − 1` such that:

1. `nums[0...p]` is strictly increasing,
2. `nums[p...q]` is strictly decreasing,
3. `nums[q...n − 1]` is strictly increasing.

Return `true` if `nums` is trionic, otherwise return `false`.

🔹 Examples:

Input: nums = [1, 3, 5, 4, 2, 6]  
Output: true  
Explanation:
Choose p = 2, q = 4  
- [1, 3, 5] → increasing  
- [5, 4, 2] → decreasing  
- [2, 6] → increasing  

Input: nums = [2, 1, 3]  
Output: false

--------------------------------------------------------------------
✅ Approach:

- Use a pointer `i` to scan the array.
- Track three phases:
  1. First strictly increasing segment.
  2. Strictly decreasing segment.
  3. Second strictly increasing segment.
- If all three segments are found and the pointer reaches the end of the array, return true.
- Otherwise, return false.

Time Complexity: O(n)
Space Complexity: O(1)
--------------------------------------------------------------------
*/

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int i = 0;

        // Phase 1: strictly increasing
        // bool increasing1 = false;
        // while (i < n - 1 && nums[i] < nums[i + 1]) {
        //     increasing1 = true;
        //     i++;
        // }

        // // Phase 2: strictly decreasing
        // bool decreasing = false;
        // while (i < n - 1 && nums[i] > nums[i + 1]) {
        //     decreasing = true;
        //     i++;
        // }

        // // Phase 3: strictly increasing
        // bool increasing2 = false;
        // while (i < n - 1 && nums[i] < nums[i + 1]) {
        //     increasing2 = true;
        //     i++;
        // }

        // // Return true if all three phases exist and we've reached the end
        // return (increasing1 && decreasing && increasing2 && i == n - 1);


        // OR  

        
        // Step 1: strictly increasing
        while (i + 1 < n && nums[i] < nums[i + 1]) ++i;
        if (i == 0 || i == n - 1) return false;

        // Step 2: strictly decreasing
        int p = i;
        while (i + 1 < n && nums[i] > nums[i + 1]) ++i;
        if (i == p || i == n - 1) return false;

        // Step 3: strictly increasing again
        while (i + 1 < n && nums[i] < nums[i + 1]) ++i;

        return i == n - 1;

    }
};

// 🧪 Test cases
int main() {
    Solution sol;

    vector<int> nums1 = {1, 3, 5, 4, 2, 6};   // true
    vector<int> nums2 = {2, 1, 3};           // false
    vector<int> nums3 = {1, 2, 3, 2, 3, 4};   // true
    vector<int> nums4 = {1, 2, 3, 4};         // false

    cout << boolalpha;  // Print true/false instead of 1/0
    cout << "Test Case 1: " << sol.isTrionic(nums1) << endl;
    cout << "Test Case 2: " << sol.isTrionic(nums2) << endl;
    cout << "Test Case 3: " << sol.isTrionic(nums3) << endl;
    cout << "Test Case 4: " << sol.isTrionic(nums4) << endl;

    return 0;
}