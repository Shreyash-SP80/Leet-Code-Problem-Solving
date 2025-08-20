#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
1277. Count Square Submatrices with All Ones
--------------------------------------------
Given an m x n binary matrix of ones and zeros, return how many square submatrices have all ones.

Example 1:
Input:
matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation:
- 10 squares of side length 1
- 4 squares of side length 2
- 1 square of side length 3
Total = 15

Example 2:
Input:
matrix =
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation:
- 6 squares of side length 1
- 1 square of side length 2
Total = 7
*/

/*
# Intuition
To count the number of square submatrices of ones, 
we need to know for each cell (i,j) how large a square of ones can end at that cell.

# Approach
- Use Dynamic Programming:
  - Let dp[i][j] represent the size of the largest square submatrix with bottom-right corner at (i,j).
  - If matrix[i][j] == 0, then dp[i][j] = 0.
  - If matrix[i][j] == 1:
    - On the first row or first column, dp[i][j] = 1.
    - Otherwise, dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1.
  - Each dp[i][j] contributes its value to the total count (because a square of size `k` includes all smaller squares too).
- Finally, return the total sum of all dp[i][j].

# Complexity
- Time Complexity: O(m * n) — we visit each cell once.
- Space Complexity: O(m * n) for dp table.  
  (Can be optimized to O(n) using a rolling array, since we only need the previous row.)
*/



class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int total = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1; // first row/col can only form 1x1 squares
                    } else {
                        dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                    }
                }
                total += dp[i][j];
            }
        }
        return total;
    }
};

// Driver code for local testing
int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {0,1,1,1},
        {1,1,1,1},
        {0,1,1,1}
    };

    cout << "Total square submatrices with all ones = " 
         << sol.countSquares(matrix) << endl;

    return 0;
}
