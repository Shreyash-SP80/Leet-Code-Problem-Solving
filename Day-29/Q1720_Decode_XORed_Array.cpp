#include <iostream>
#include <vector>
using namespace std;

/*
1720. Decode XORed Array
------------------------
We are given an encoded array such that:
- encoded[i] = arr[i] XOR arr[i+1]
We also know the first element of the original array: arr[0] = first.

We must decode and return the original array.
*/

/*
# Intuition
- From XOR properties:
  arr[i+1] = encoded[i] XOR arr[i].
- Since we know arr[0] = first, we can reconstruct each next element step by step.

# Approach
1. Initialize result array with `first`.
2. For each number in encoded:
   - Compute next element = previous element XOR encoded[i].
   - Append it to result.
3. Return the result array.

# Complexity
- Time: O(n), we iterate once through encoded.
- Space: O(n), for storing the decoded array.
*/


class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> result = {first};
        for (int num : encoded) {
            first ^= num;              // arr[i+1] = arr[i] XOR encoded[i]
            result.push_back(first);
        }
        return result;
    }
};

// Driver
int main() {
    Solution sol;

    vector<int> encoded1 = {1, 2, 3};
    int first1 = 1;
    for (int x : sol.decode(encoded1, first1)) cout << x << " "; // 1 0 2 1
    cout << endl;

    vector<int> encoded2 = {6, 2, 7, 3};
    int first2 = 4;
    for (int x : sol.decode(encoded2, first2)) cout << x << " "; // 4 2 0 7 4
    cout << endl;

    return 0;
}
