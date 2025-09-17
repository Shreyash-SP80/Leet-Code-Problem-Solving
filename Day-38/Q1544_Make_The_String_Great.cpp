#include<iostream>
using namespace std;


class Solution {
public:
    string makeGood(string s) {
        string result;

        for (char c: s) {
            if (!result.empty() && abs(result.back() - c) == 32) {
                result.pop_back(); // remove bad pair
            } else {
                result.push_back(c); // keep valid char
            }
        }
        return result;
    }
};

// --------------------
// Driver Code
// --------------------
int main() {
    Solution sol;

    string s1 = "leEeetcode";
    cout << "Input: " << s1 << "\n";
    cout << "Output: " << sol.makeGood(s1) << "\n\n";

    string s2 = "abBAcC";
    cout << "Input: " << s2 << "\n";
    cout << "Output: " << sol.makeGood(s2) << "\n\n";

    string s3 = "s";
    cout << "Input: " << s3 << "\n";
    cout << "Output: " << sol.makeGood(s3) << "\n";

    return 0;
}



