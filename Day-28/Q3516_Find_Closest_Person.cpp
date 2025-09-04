#include <iostream>
#include <cmath>
using namespace std;

/*
3516. Find Closest Person
--------------------------
We are given positions of three people on a number line:
- Person 1 at x
- Person 2 at y
- Person 3 at z (does not move)

Both Person 1 and Person 2 move toward Person 3 at the same speed.
We must determine:
- Return 1 if Person 1 reaches Person 3 first.
- Return 2 if Person 2 reaches Person 3 first.
- Return 0 if both reach at the same time.
*/

/*
# Intuition
- The key is to compare distances from each person to Person 3.
- Distance of Person 1 = |x - z|
- Distance of Person 2 = |y - z|
- The one with smaller distance reaches first.
- If equal, both reach at the same time.

# Approach
1. Compute dx = abs(x - z) and dy = abs(y - z).
2. Compare:
   - If dx == dy → return 0
   - If dx < dy  → return 1
   - Else        → return 2

# Complexity
- Time: O(1) (just comparisons).
- Space: O(1).
*/



class Solution {
public:
    int findClosest(int x, int y, int z) {
        int dx = abs(x - z);
        int dy = abs(y - z);

        if (dx == dy) return 0;
        return (dx < dy) ? 1 : 2;
    }
};

// Driver
int main() {
    Solution sol;

    cout << sol.findClosest(2, 7, 4) << endl; // Output: 1
    cout << sol.findClosest(2, 5, 6) << endl; // Output: 2
    cout << sol.findClosest(1, 5, 3) << endl; // Output: 0

    return 0;
}
