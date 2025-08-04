#include <iostream>
#include <vector>
using namespace std;


/*
===========================================
🧩 LeetCode 27. Remove Element
===========================================

📌 Problem Statement:
---------------------
Given an integer array `nums` and an integer `val`, remove all occurrences of `val` **in-place**.
The relative order of the elements may be changed.

🔁 Requirements:
- Modify the array `nums` in-place such that the first `k` elements do **not** contain `val`.
- Return the value of `k`, the number of elements not equal to `val`.
- It does **not** matter what values are left beyond index `k`.

📥 Example 1:
Input:  nums = [3,2,2,3], val = 3  
Output: 2, nums = [2,2,_,_]

📥 Example 2:
Input:  nums = [0,1,2,2,3,0,4,2], val = 2  
Output: 5, nums = [0,1,4,0,3,_,_,_]

-------------------------------------------
🧠 Approach:
-------------------------------------------
1. Initialize a pointer `k = 0` to track the position to overwrite.
2. Iterate through the array:
   - If current element is **not equal** to `val`, copy it to `nums[k]`, and increment `k`.
3. After the loop, the first `k` elements will be the values not equal to `val`.
4. Return `k`.

🔧 Time Complexity: O(n)
🔧 Space Complexity: O(1) (in-place)
===========================================
*/



class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;  // Counter for non-val elements

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i]; // Overwrite val element
                k++;               // Move pointer forward
            }
        }

        return k;  // Return count of elements not equal to val
    }
};

// ✅ Example usage
int main() {
    Solution sol;

    // Example input
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;

    // Call the function
    int k = sol.removeElement(nums, val);

    // Output result
    cout << "k = " << k << endl;
    cout << "Updated array: ";
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
