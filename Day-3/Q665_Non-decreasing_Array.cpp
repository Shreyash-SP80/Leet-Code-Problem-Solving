#include <iostream>
#include <vector>
using namespace std;



// ✅ APPROACH:
//
// The goal is to check if the array can become non-decreasing
// by modifying **at most one element**.
//
// A non-decreasing array means: nums[i] <= nums[i+1] for all i.
//
// STEP 1: Traverse the array and count how many times nums[i-1] > nums[i].
// If it happens **more than once**, return false.
//
// STEP 2: When nums[i-1] > nums[i] is found, try to fix it in one of two ways:
//   - Case 1: If i < 2 OR nums[i-2] <= nums[i], it's safe to modify nums[i-1] = nums[i].
//     (We are lowering the higher value to maintain order.)
//   - Case 2: Else, modify nums[i] = nums[i-1].
//     (We are raising the smaller value to match the previous one.)
//
// These changes ensure the array remains non-decreasing without breaking earlier order.
//
// ✅ Time Complexity: O(n)
// ✅ Space Complexity: O(1)


class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count = 0;
        int n = nums.size();

        for (int i = 1; i < n; i++) {
            if (nums[i - 1] > nums[i]) {
                count++;

                if (count > 1) {
                    return false;
                }

                // Decide which value to modify to maintain non-decreasing order
                if (i < 2 || nums[i - 2] <= nums[i]) {
                    nums[i - 1] = nums[i];
                } else {
                    nums[i] = nums[i - 1];
                }
            }
        }

        return true;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 4, 1, 2};

    bool result = sol.checkPossibility(nums);

    if (result)
        cout << "True\n";  // Only one change needed to make array non-decreasing
    else
        cout << "False\n";

    return 0;
}
