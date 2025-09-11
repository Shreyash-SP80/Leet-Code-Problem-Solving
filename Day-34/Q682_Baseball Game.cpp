#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int result = 0;

        for (string c : operations) {
            if (c == "C") {
                // Invalidate the last score
                st.pop();
            } 
            else if (c == "D") {
                // Double the last score
                int lastDigit = st.top();
                st.push(2 * lastDigit);
            } 
            else if (c == "+") {
                // Add the last two scores
                int digit2 = st.top();
                st.pop();
                int digit1 = st.top();
                st.push(digit2); // restore
                st.push(digit1 + digit2);
            } 
            else {
                // Record a new score
                st.push(stoi(c));
            }
        }

        // Sum all scores
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        return result;
    }
};

// Driver code
int main() {
    Solution sol;

    vector<string> ops1 = {"5","2","C","D","+"};
    cout << "Output 1: " << sol.calPoints(ops1) << endl; 
    // Expected: 30

    vector<string> ops2 = {"5","-2","4","C","D","9","+","+"};
    cout << "Output 2: " << sol.calPoints(ops2) << endl; 
    // Expected: 27

    vector<string> ops3 = {"1","C"};
    cout << "Output 3: " << sol.calPoints(ops3) << endl; 
    // Expected: 0

    return 0;

}

// Output => 
// Output 1: 30
// Output 2: 27
// Output 3: 0


