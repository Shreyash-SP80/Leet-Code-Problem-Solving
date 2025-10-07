#include <iostream>
#include <stack>
#include <string>
using namespace std;





class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int max = 0;

        for (char c: s) {
            if (c == '(') {
                st.push(c);
                int curr = st.size();
                if (curr > max) 
                    max = curr;
            } else if (c == ')') {
                if (!st.empty()) 
                    st.pop();
            }
            // Ignore other characters
        }

        return max;
    }
};

// ------------------- MAIN FUNCTION -------------------
int main() {
    Solution solution;
    string s;

    cout << "Enter a valid parentheses string: ";
    getline(cin, s);

    int result = solution.maxDepth(s);
    cout << "Maximum nesting depth is: " << result << endl;

    return 0;
}
