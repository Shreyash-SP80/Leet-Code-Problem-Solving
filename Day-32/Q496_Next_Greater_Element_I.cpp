#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

/*
496. Next Greater Element I
--------------------------------------------
We are given two integer arrays nums1 and nums2, where nums1 is a subset of nums2.
The "next greater element" of a number x in nums2 is the first number to the right of x
in nums2 that is strictly greater than x. If none exists, return -1.

We must return an array ans such that ans[i] corresponds to the next greater element
for nums1[i].
*/

/*
# Intuition
- A brute force way is to search to the right of each element in nums2 for the next
  greater element. This works but is O(n^2).
- Optimized approach: Use a **monotonic stack**.
  - Traverse nums2 from left to right.
  - Maintain a stack of decreasing elements.
  - For each element `num`, while stack top < num:
        * Pop stack top.
        * The "next greater" of that popped element is `num`.
  - Push current element onto stack.
- At the end, elements left in stack have no next greater → implicitly mapped to -1.

# Approach
1. Use a stack to build a map of {element → nextGreater}.
2. Traverse nums2:
   - Pop from stack while top < current num, assign mapping.
   - Push current num.
3. For each num in nums1, lookup in map:
   - If exists → use mapped value.
   - If not → -1.
4. Return results.

# Complexity
- Time: O(n), since each element is pushed/popped at most once.
- Space: O(n) for stack + map.
*/


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        // BroutForce Approch =>
        // vector<int> ans;

        // for (int i = 0; i < nums1.size(); i++) {
            
        //     bool found = false;
        //     int  nextGreater = -1;

        //     for (int j = 0; j < nums2.size(); j++) {
        //         if (nums1[i] == nums2[j]) {
        //             found = true;
        //         }
        //         if (found && nums2[j] > nums1[i]) {
        //             nextGreater = nums2[j];
        //             break;
        //         }
        //     }
        //     ans.push_back(nextGreater);
        // }

        // return ans;

        // Using stack
        unordered_map<int, int> nextGreater;
        stack<int> st;

        // Build next greater mapping for nums2
        for (int num : nums2) {
            while (!st.empty() && st.top() < num) {
                nextGreater[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        // Prepare answer for nums1 using the map
        vector<int> ans;
        for (int num : nums1) {
            ans.push_back(nextGreater.count(num) ? nextGreater[num] : -1);
            // nextGreater.count(num) this can check the key exists or not if exists the return 1 if not then return 0 (boolen values) i.e if 1 the num has next greater element if not then no greater element
        }
        return ans;
    }
};

// Driver
int main() {
    Solution sol;

    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};
    for (int x : sol.nextGreaterElement(nums1, nums2)) cout << x << " "; 
    cout << endl; // -1 3 -1

    vector<int> nums3 = {2,4};
    vector<int> nums4 = {1,2,3,4};
    for (int x : sol.nextGreaterElement(nums3, nums4)) cout << x << " "; 
    cout << endl; // 3 -1

    return 0;
}



