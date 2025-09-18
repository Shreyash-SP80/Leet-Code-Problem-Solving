#include <iostream>
using namespace std;



class Solution {
public:
    int minAddToMakeValid(string s) {
        int balance = 0;    // count of unmatched '('
        int insertion = 0;  // count of needed insertions

        for (char c: s) {
            if (c == '(') {
                balance++;
            } else {
                if (balance > 0) {
                    balance--;  // match with an open bracket
                } else {
                    insertion++; // need an extra '('
                }
            }
        }

        return balance + insertion;
    }
};

// --------------------
// Driver Code
// --------------------
int main() {
    Solution sol;

    string s1 = "())";
    cout << "Input: \"())\"\nOutput: " << sol.minAddToMakeValid(s1) << "\n\n";

    string s2 = "(((";
    cout << "Input: \"((\"\nOutput: " << sol.minAddToMakeValid(s2) << "\n\n";

    string s3 = "()";
    cout << "Input: \"()\"\nOutput: " << sol.minAddToMakeValid(s3) << "\n\n";

    string s4 = "()))((";
    cout << "Input: \"()))((\"\nOutput: " << sol.minAddToMakeValid(s4) << "\n";

    return 0;
}


