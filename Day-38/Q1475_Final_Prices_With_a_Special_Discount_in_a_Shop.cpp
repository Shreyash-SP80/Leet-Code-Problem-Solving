#include <iostream>
#include<vector>
#include<stack>
using namespace std;

/**
 * 1475. Final Prices With a Special Discount in a Shop
 * ----------------------------------------------------
 * Approach:
 * - We need to find for each item `i` the first item `j > i` such that prices[j] <= prices[i].
 * - If such `j` exists → discount = prices[j], otherwise no discount.
 * - Naive O(n^2) solution: For each item, look forward linearly.
 * - Optimized O(n) solution using a stack:
 *      - Traverse the array from left to right.
 *      - Maintain a stack of indices of items whose discount hasn't been found yet.
 *      - While current price <= price at top of stack, pop stack and apply discount.
 * - This ensures each index is pushed and popped at most once → O(n).
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n) for stack
 */

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> result = prices; // start with original prices
        stack<int> st;               // store indices

        for (int i = 0; i < n; i++) {
            // While current price <= price at top index → discount found
            while (!st.empty() && prices[i] <= prices[st.top()]) {
                result[st.top()] -= prices[i]; // apply discount
                st.pop();
            }
            st.push(i);
        }
        return result;
    }
};

// --------------------
// Driver Code
// --------------------

int main() {
    Solution sol;

    vector<int> prices1 = {8,4,6,2,3};
    vector<int> ans1 = sol.finalPrices(prices1);
    cout << "Input: [8,4,6,2,3]\nOutput: [";
    for (int i = 0; i < ans1.size(); i++) {
        cout << ans1[i] << (i + 1 < ans1.size() ? "," : "");
    }
    cout << "]\n\n";

    vector<int> prices2 = {1,2,3,4,5};
    vector<int> ans2 = sol.finalPrices(prices2);
    cout << "Input: [1,2,3,4,5]\nOutput: [";
    for (int i = 0; i < ans2.size(); i++) {
        cout << ans2[i] << (i + 1 < ans2.size() ? "," : "");
    }
    cout << "]\n\n";

    vector<int> prices3 = {10,1,1,6};
    vector<int> ans3 = sol.finalPrices(prices3);
    cout << "Input: [10,1,1,6]\nOutput: [";
    for (int i = 0; i < ans3.size(); i++) {
        cout << ans3[i] << (i + 1 < ans3.size() ? "," : "");
    }
    cout << "]\n";

    return 0;
}


/*
Expected Output:

Input: [8,4,6,2,3]
Output: [4,2,4,2,3]

Input: [1,2,3,4,5]
Output: [1,2,3,4,5]

Input: [10,1,1,6]
Output: [9,0,1,6]
*/




