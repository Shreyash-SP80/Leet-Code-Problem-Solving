
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int maxFreqSum(string s) {
        string vowels = "aeiou";
        unordered_map<char, int> freq;

        // Count frequencies
        for (char c : s) {
            freq[c]++;
        }

        int maxVowel = 0, maxConsonant = 0;

        // Find max frequency vowel & consonant
        for (auto &p : freq) {
            if (vowels.find(p.first) != string::npos) {
                maxVowel = max(maxVowel, p.second);
            } else {
                maxConsonant = max(maxConsonant, p.second);
            }
        }

        return maxVowel + maxConsonant;
    }
};

// Driver code
int main() {
    Solution sol;

    string s1 = "successes";
    cout << "Input: " << s1 << "\nOutput: " << sol.maxFreqSum(s1) << endl;
    // Expected: 6

    string s2 = "aeiaeia";
    cout << "Input: " << s2 << "\nOutput: " << sol.maxFreqSum(s2) << endl;
    // Expected: 3

    return 0;
}
