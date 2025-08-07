
#include <iostream>
#include <vector>
using namespace std;

/*
===========================================================================
🧮 LeetCode Problem: 2022. Convert 1D Array Into 2D Array
🔗 Link: https://leetcode.com/problems/convert-1d-array-into-2d-array/
💡 Difficulty: Easy
===========================================================================

📘 Problem Statement:
You are given a 0-indexed 1-dimensional (1D) integer array `original`, and two integers `m` and `n`.

Your task is to create a 2-dimensional (2D) array with `m` rows and `n` columns using all the elements from `original`.

The construction should be as follows:
- The elements from indices 0 to n - 1 of original become the first row.
- The elements from indices n to 2n - 1 become the second row.
- And so on, until all elements are used.

⚠️ If it is not possible to construct such a 2D array (i.e., m * n != original.size()), return an empty 2D array.

-------------------------------------------------------------------------------
🔍 Example 1:
Input:  original = [1, 2, 3, 4], m = 2, n = 2
Output: [[1, 2], [3, 4]]

🔍 Example 2:
Input:  original = [1, 2, 3], m = 1, n = 3
Output: [[1, 2, 3]]

🔍 Example 3:
Input:  original = [1, 2], m = 1, n = 1
Output: []

-------------------------------------------------------------------------------
🧠 Approach:

1️⃣ First check if the total number of elements (`original.size()`) equals `m * n`.
   - If not, return an empty matrix.

2️⃣ Initialize a 2D vector `matrix` of size m x n.

3️⃣ Iterate through each index of the 1D array:
    - Use index math:
        - Row index = i / n
        - Column index = i % n
    - Place the original[i] into matrix[row][col].

4️⃣ Return the constructed matrix.

🕒 Time Complexity: O(m * n)
🛢️ Space Complexity: O(m * n)

===============================================================================
*/


class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        // Step 1: Check if transformation is possible
        if (original.size() != m * n) {
            return {};  // Return empty 2D array if not possible
        }

        // Step 2: Create an m x n 2D vector filled with 0s
        vector<vector<int>> matrix(m, vector<int>(n));

        // Step 3: Fill the matrix using index math
        for (int i = 0; i < m * n; ++i) {
            matrix[i / n][i % n] = original[i];  // Row = i / n, Col = i % n
        }

        return matrix;
    }
};

// 📌 Main function to test the solution
int main() {
    Solution sol;

    vector<int> original = {1, 2, 3, 4};
    int m = 2, n = 2;

    vector<vector<int>> result = sol.construct2DArray(original, m, n);

    // 🖨️ Print the result
    cout << "Output 2D Array:" << endl;
    if (result.empty()) {
        cout << "[]" << endl;
    } else {
        for (const auto& row : result) {
            cout << "[ ";
            for (int val : row) {
                cout << val << " ";
            }
            cout << "]" << endl;
        }
    }

    return 0;
}

// Output 2D Array:
// [ 1 2 ]
// [ 3 4 ]

