#include <iostream>
#include <vector>
using namespace std;

/*
3477. Fruits Into Baskets II

You are given two arrays of integers, `fruits` and `baskets`, each of length `n`, where:
- `fruits[i]` represents the quantity of the ith type of fruit.
- `baskets[j]` represents the capacity of the jth basket.

Rules:
1. From left to right, each fruit must be placed in the **leftmost available** basket that has capacity >= fruit's quantity.
2. Each basket can hold only **one type** of fruit.
3. If a fruit can't be placed in any basket, it remains unplaced.

Return the number of **unplaced fruit types** after all possible allocations.

Approach:
- For each fruit, find the first unused basket that can hold it.
- If found, place it and mark the basket as used.
- If not, increase the unplaced fruit counter.

Time Complexity: O(n^2)
Space Complexity: O(n)


Source Link: https://leetcode.com/problems/fruits-into-baskets-ii/

*/

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<int> isEmptyBasket(n, 0);  // Track basket usage
        int unplacedCount = 0;

        for (int i = 0; i < n; i++) {
            bool placed = false;

            for (int j = 0; j < n; j++) {
                if (!isEmptyBasket[j] && baskets[j] >= fruits[i]) {
                    isEmptyBasket[j] = 1; // Mark as used
                    placed = true;
                    break;
                }
            }

            if (!placed) unplacedCount++;
        }

        return unplacedCount;
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> fruits1 = {4, 2, 5};
    vector<int> baskets1 = {3, 5, 4};
    cout << "Test Case 1 Output: " << sol.numOfUnplacedFruits(fruits1, baskets1) << endl;
    // Expected output: 1

    // Test case 2
    vector<int> fruits2 = {3, 6, 1};
    vector<int> baskets2 = {6, 4, 7};
    cout << "Test Case 2 Output: " << sol.numOfUnplacedFruits(fruits2, baskets2) << endl;
    // Expected output: 0

    // Test case 3
    vector<int> fruits3 = {1, 2, 3};
    vector<int> baskets3 = {1, 2, 3};
    cout << "Test Case 3 Output: " << sol.numOfUnplacedFruits(fruits3, baskets3) << endl;
    // Expected output: 0

    // Test case 4
    vector<int> fruits4 = {5, 5, 5};
    vector<int> baskets4 = {1, 2, 3};
    cout << "Test Case 4 Output: " << sol.numOfUnplacedFruits(fruits4, baskets4) << endl;
    // Expected output: 3

    // Test case 5
    vector<int> fruits5 = {2, 1, 3};
    vector<int> baskets5 = {3, 2, 1};
    cout << "Test Case 5 Output: " << sol.numOfUnplacedFruits(fruits5, baskets5) << endl;
    // Expected output: 0

    return 0;
}
