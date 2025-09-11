#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string sortVowels(string s) {
        string vowels = "aeiouAEIOU";
        vector<char> v;

        // Step 1: Extract vowels
        for (char c : s) {
            if (vowels.find(c) != string::npos) {   // string::npos -> not found
                v.push_back(c);
            }
        }

        // Step 2: Sort vowels
        sort(v.begin(), v.end());

        // Step 3: Replace vowels in order
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            if (vowels.find(s[i]) != string::npos) {
                s[i] = v[j++];
            }
        }
        return s;
    }
};

// Driver code
int main() {
    Solution sol;

    string s1 = "lEetcOde";
    cout << "Input: " << s1 << "\nOutput: " << sol.sortVowels(s1) << endl;
    // Expected: lEOtcede

    string s2 = "lYmpH";
    cout << "Input: " << s2 << "\nOutput: " << sol.sortVowels(s2) << endl;
    // Expected: lYmpH

    return 0;

}
