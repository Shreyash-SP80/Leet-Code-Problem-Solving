#include <iostream>
#include<vector>
#include<stack>
using namespace std;



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


