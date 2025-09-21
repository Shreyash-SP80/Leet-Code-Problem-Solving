
#include <iostream>
#inlcude <vector>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26, 0);
        vector<bool> visited(26, false);

        // Count frequency of each character
        for (char c : s) freq[c - 'a']++;

        string result = "";
        for (char c : s) {
            freq[c - 'a']--;  // Decrease frequency since we are processing it

            if (visited[c - 'a']) continue; // Skip if already in result

            // Maintain lexicographical order
            while (!result.empty() && result.back() > c && freq[result.back() - 'a'] > 0) {
                visited[result.back() - 'a'] = false;
                result.pop_back();
            }
            result.push_back(c);
            visited[c - 'a'] = true;
        }
        return result;
    }
};

// Driver code
int main() {
    Solution sol;

    string s1 = "bcabc";
    cout << "Input: " << s1 << endl;
    cout << "Output: " << sol.removeDuplicateLetters(s1) << endl;

    string s2 = "cbacdcbc";
    cout << "Input: " << s2 << endl;
    cout << "Output: " << sol.removeDuplicateLetters(s2) << endl;

    return 0;
}






