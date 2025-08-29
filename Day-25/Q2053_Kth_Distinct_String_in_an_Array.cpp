#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
2053. Kth Distinct String in an Array
-------------------------------------
A distinct string is a string that appears exactly once in the array.

Given an array of strings `arr` and an integer `k`, return the k-th distinct string
in the order it appears. If there are fewer than k distinct strings, return "".

Example 1:
Input: arr = ["d","b","c","b","c","a"], k = 2
Output: "a"

Example 2:
Input: arr = ["aaa","aa","a"], k = 1
Output: "aaa"

Example 3:
Input: arr = ["a","b","a"], k = 3
Output: ""
*/

/*
# Intuition
- We need the k-th string that occurs **exactly once** in the array, while preserving input order.
- First, count occurrences of each string.
- Then, iterate again in order: 
  - For each string with frequency 1, decrement `k`.
  - When `k` reaches 0, return that string.
- If we finish without finding k distinct strings → return "".

# Approach
1. Use `unordered_map<string,int>` to count frequencies.
2. Iterate over `arr` in original order to track distinct elements.
3. Return the k-th distinct string, or "" if not enough exist.

# Complexity
- Time: O(n) → one pass for frequency + one pass for order.
- Space: O(n) → to store frequencies.
*/



class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> freq;

        // Count frequency of each string
        for (auto &s: arr) {
            freq[s]++;
        }

        // Traverse again to find the k-th distinct
        for (auto &s: arr) {
            if (freq[s] == 1) {
                k--;
                if (k == 0) {
                    return s;
                }
            }
        }

        return "";
    }
};

// Driver code
int main() {
    Solution sol;

    vector<string> arr1 = {"d","b","c","b","c","a"};
    cout << "Output 1: " << sol.kthDistinct(arr1, 2) << endl; // "a"

    vector<string> arr2 = {"aaa","aa","a"};
    cout << "Output 2: " << sol.kthDistinct(arr2, 1) << endl; // "aaa"

    vector<string> arr3 = {"a","b","a"};
    cout << "Output 3: " << sol.kthDistinct(arr3, 3) << endl; // ""

    return 0;
}
