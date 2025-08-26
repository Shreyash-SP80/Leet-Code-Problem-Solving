#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
3000. Maximum Area of Longest Diagonal Rectangle
------------------------------------------------
You are given a 2D 0-indexed integer array `dimensions`.

- dimensions[i][0] = length of rectangle i
- dimensions[i][1] = width of rectangle i

Return the area of the rectangle having the **longest diagonal**.  
If multiple rectangles have the same diagonal length, return the area of the rectangle with the **maximum area**.

Example 1:
Input: dimensions = [[9,3],[8,6]]
Output: 48
Explanation: 
Diagonal lengths: sqrt(9^2 + 3^2) ≈ 9.487, sqrt(8^2 + 6^2) = 10
Rectangle with longest diagonal: [8,6], area = 8*6 = 48

Example 2:
Input: dimensions = [[3,4],[4,3]]
Output: 12
Explanation:
Both have diagonal length = 5, max area = 12
*/

/*
# Intuition
- Diagonal length = sqrt(length^2 + width^2)
- Track the maximum diagonal found so far and its corresponding area.
- If two rectangles have same diagonal, pick the one with larger area.

# Approach
1. Initialize `max_diagonal = 0` and `max_area = 0`.
2. Iterate over all rectangles:
   - Compute `diagonal = sqrt(length^2 + width^2)`
   - If diagonal > max_diagonal:
       - update max_diagonal and max_area
   - Else if diagonal == max_diagonal:
       - update max_area = max(max_area, length*width)
3. Return `max_area`.

# Complexity
- Time: O(n), n = number of rectangles
- Space: O(1)
*/



class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double max_diagonal = 0;
        int max_area = 0;

        for (auto &rect : dimensions) {
            int length = rect[0];
            int width = rect[1];
            double diagonal = sqrt(length * length + width * width);

            if (diagonal > max_diagonal) {
                max_diagonal = diagonal;
                max_area = length * width;
            } else if (diagonal == max_diagonal) {
                max_area = max(max_area, length * width);
            }
        }

        return max_area;
    }
};

// Driver code
int main() {
    Solution sol;

    vector<vector<int>> dims1 = {{9,3},{8,6}};
    cout << "Output 1: " << sol.areaOfMaxDiagonal(dims1) << endl; // 48

    vector<vector<int>> dims2 = {{3,4},{4,3}};
    cout << "Output 2: " << sol.areaOfMaxDiagonal(dims2) << endl; // 12

    vector<vector<int>> dims3 = {{5,12},{6,8},{3,4}};
    cout << "Output 3: " << sol.areaOfMaxDiagonal(dims3) << endl; // 60

    return 0;
}
