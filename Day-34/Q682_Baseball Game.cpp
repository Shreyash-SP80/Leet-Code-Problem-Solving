#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

/*
===========================
   LeetCode 682. Baseball Game
===========================

You are keeping scores for a baseball game with strange rules. At the beginning 
of the game, you start with an empty record.

You are given a list of strings `operations`, where:
- An integer x: record a new score of x.
- "+" : record a new score that is the sum of the previous two scores.
- "D" : record a new score that is the double of the previous score.
- "C" : invalidate the previous score, removing it from the record.

Return the sum of all the scores on the record.

===========================
Examples:
---------------------------
Input: ["5","2","C","D","+"]
Output: 30
Explanation: Record becomes [5, 10, 15].

Input: ["5","-2","4","C","D","9","+","+"]
Output: 27

Input: ["1","C"]
Output: 0
===========================

Approach:
1. Use a stack to maintain valid scores.
2. Traverse through each operation:
   - If "C": remove the last score (stack pop).
   - If "D": push double of the last score.
   - If "+": push sum of the last two scores.
   - Else: convert string to integer and push it.
3. After processing all operations, pop all values from the stack 
   and calculate the total sum.
4. Return the result.

Time Complexity: O(n)   (we iterate through all operations once)
Space Complexity: O(n)  (stack stores scores)
*/

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



