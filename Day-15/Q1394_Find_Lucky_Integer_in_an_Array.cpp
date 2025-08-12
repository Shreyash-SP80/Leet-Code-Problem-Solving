#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;



/*
====================================================================
Problem: 1394. Find Lucky Integer in an Array
====================================================================
Given an array of integers arr, a lucky integer is an integer that 
has a frequency in the array equal to its value.

Return the largest lucky integer in the array. 
If there is no lucky integer return -1.

--------------------------------------------------------------------
Example 1:
Input: arr = [2,2,3,4]
Output: 2
Explanation: The only lucky number in the array is 2 because frequency[2] == 2.

Example 2:
Input: arr = [1,2,2,3,3,3]
Output: 3
Explanation: 1, 2 and 3 are all lucky numbers, return the largest of them.

Example 3:
Input: arr = [2,2,2,3,3]
Output: -1
Explanation: There are no lucky numbers in the array.
--------------------------------------------------------------------

Approach:
1. Use an unordered_map<int, int> to store the frequency of each element.
2. Iterate through the array and populate the frequency map.
3. Sort the array so that larger numbers are processed last (ensuring largest lucky number overwrites smaller ones).
4. Traverse the sorted array:
   - If current element equals its frequency in the map, store it in ans.
5. Return ans if non-zero, else return -1.

--------------------------------------------------------------------
Complexity:
- Time Complexity: O(n log n) 
  (O(n) for counting frequencies + O(n log n) for sorting + O(n) for checking)
- Space Complexity: O(n) for frequency map.
====================================================================
*/


class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;
        int ans = 0;

        // Count frequencies
        for (int num : arr) {
            freq[num]++;
        }

        // Sort the array so larger lucky numbers overwrite smaller ones
        sort(arr.begin(), arr.end());

        // Check for lucky integers
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == freq[arr[i]]) {
                ans = arr[i];
            }
            i++; // Skips duplicates faster
        }

        return ans ? ans : -1;
    }
};

int main() {
    Solution sol;

    vector<int> arr1 = {2, 2, 3, 4};
    cout << "Output: " << sol.findLucky(arr1) << endl; // Expected 2

    vector<int> arr2 = {1, 2, 2, 3, 3, 3};
    cout << "Output: " << sol.findLucky(arr2) << endl; // Expected 3

    vector<int> arr3 = {2, 2, 2, 3, 3};
    cout << "Output: " << sol.findLucky(arr3) << endl; // Expected -1

    return 0;
}
