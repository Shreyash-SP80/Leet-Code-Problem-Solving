#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

/*
1331. Rank Transform of an Array
---------------------------------
Given an array of integers `arr`, replace each element with its rank.

Rules:
1. Rank is an integer starting from 1.
2. Larger elements have larger ranks.
3. Equal elements share the same rank.
4. Ranks should be as small as possible.

Example 1:
Input: arr = [40,10,20,30]
Output: [4,1,2,3]

Example 2:
Input: arr = [100,100,100]
Output: [1,1,1]

Example 3:
Input: arr = [37,12,28,9,100,56,80,5,12]
Output: [5,3,4,2,8,6,7,1,3]
*/

/*
# Intuition
- Sort unique elements to determine the order.
- Map each number to its rank.
- Replace each element in original array with its rank.

# Approach
1. Copy `arr` into `sortedArray` and sort it.
2. Use a map `rankMap` to store number → rank.
3. Assign ranks incrementally for unique numbers.
4. Replace each element in `arr` using `rankMap`.

# Complexity
- Time: O(n log n), due to sorting
- Space: O(n), for map and copy
*/



class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sortedArray = arr;
        sort(sortedArray.begin(), sortedArray.end());

        map<int, int> rankMap;
        int rank = 1;

        for (int num : sortedArray) {
            if (rankMap.find(num) == rankMap.end()) {
                rankMap[num] = rank++;
            }
        }

        for (int i = 0; i < arr.size(); i++) {
            arr[i] = rankMap[arr[i]];
        }

        return arr;
    }
};

// Driver code
int main() {
    Solution sol;

    vector<int> arr1 = {40,10,20,30};
    auto res1 = sol.arrayRankTransform(arr1);
    cout << "Output 1: ";
    for (int x : res1) cout << x << " ";
    cout << endl;

    vector<int> arr2 = {100,100,100};
    auto res2 = sol.arrayRankTransform(arr2);
    cout << "Output 2: ";
    for (int x : res2) cout << x << " ";
    cout << endl;

    vector<int> arr3 = {37,12,28,9,100,56,80,5,12};
    auto res3 = sol.arrayRankTransform(arr3);
    cout << "Output 3: ";
    for (int x : res3) cout << x << " ";
    cout << endl;

    return 0;
}
