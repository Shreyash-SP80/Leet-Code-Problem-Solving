#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*
===========================================
🧩 LeetCode 845. Longest Mountain in Array
===========================================

📌 Description:
----------------
You may recall that an array arr is a *mountain array* if and only if:
- arr.length >= 3
- There exists some index i (0 < i < arr.length - 1) such that:
    - arr[0] < arr[1] < ... < arr[i-1] < arr[i]
    - arr[i] > arr[i+1] > ... > arr[arr.length - 1]

🔍 Task:
---------
Given an integer array arr, return the length of the longest subarray that is a mountain.
Return 0 if there is no mountain.

🔸 Example 1:
Input: arr = [2,1,4,7,3,2,5]
Output: 5
Explanation: The longest mountain is [1,4,7,3,2]

🔸 Example 2:
Input: arr = [2,2,2]
Output: 0
Explanation: No mountain exists.

-------------------------------------------
🧠 Approach:
-------------------------------------------
1. Traverse the array using a pointer `i` starting from index 1 to n-2.
2. At each step, check if `arr[i]` is a **peak** (i.e., `arr[i-1] < arr[i] > arr[i+1]`).
3. If a peak is found:
    - Expand left while the sequence is strictly increasing.
    - Expand right while the sequence is strictly decreasing.
    - Update `maxlen` with the length of this mountain (`right - left + 1`).
4. Move `i` to the end of the current mountain to avoid rechecking.
5. Continue until the end of the array.

🔧 Time Complexity: O(n)
🔧 Space Complexity: O(1)
===========================================
*/



class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int maxlen = 0;
        int i = 1;  // Start from second element

        while (i < n - 1) {
            // Check if current element is a peak
            if (arr[i-1] < arr[i] && arr[i] > arr[i+1]) {
                int left = i - 1;
                int right = i + 1;

                // Move left while strictly increasing
                while (left > 0 && arr[left] > arr[left - 1]) {
                    left--;
                }

                // Move right while strictly decreasing
                while (right < n - 1 && arr[right] > arr[right + 1]) {
                    right++;
                }

                // Update maximum length
                maxlen = max(maxlen, right - left + 1);

                // Skip to end of current mountain
                i = right;
            } else {
                i++;
            }
        }

        return maxlen;
    }
};

// ✅ Example usage
int main() {
    Solution sol;
    vector<int> arr = {2, 1, 4, 7, 3, 2, 5};
    cout << "Longest Mountain Length: " << sol.longestMountain(arr) << endl;
    return 0;
}
