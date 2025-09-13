
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool doesAliceWin(string s) {
        string vowels = "aeiou";

        for (char c : s) {
            if (vowels.find(c) != string::npos) {
                return true;   // Found a vowel → Alice wins
            }
        }
        return false;          // No vowel → Alice cannot move → loses
    }
};

// Driver code
int main() {
    Solution sol;

    string s1 = "leetcoder";
    cout << "Input: " << s1 << "\nOutput: "
         << (sol.doesAliceWin(s1) ? "true" : "false") << endl;
    // Expected: true

    string s2 = "bbcd";
    cout << "Input: " << s2 << "\nOutput: "
         << (sol.doesAliceWin(s2) ? "true" : "false") << endl;
    // Expected: false

    return 0;
}
