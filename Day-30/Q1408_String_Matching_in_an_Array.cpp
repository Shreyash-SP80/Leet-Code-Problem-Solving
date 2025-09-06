#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
1408. String Matching in an Array
---------------------------------
We are given an array of strings words.
We need to return all strings in words that are a substring of another string in the array.
*/

/*
# Intuition
- A word is valid if it appears inside another longer word in the list.
- Example: "as" is inside "mass", so it should be included.

# Approach
1. For each word[i], compare with every other word[j].
2. If word[i] is a substring of word[j] (i != j), add word[i] to the result.
3. Break after the first match (to avoid duplicates).
4. Return the result.

# Complexity
- Time: O(n^2 * m), where:
  - n = number of words
  - m = average length of strings
- Space: O(k), where k = number of matching substrings.
*/


class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> result;
        int n = words.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && words[j].find(words[i]) != string::npos) {
                    result.push_back(words[i]);
                    break; // avoid adding same word multiple times
                }
            }
        }
        return result;
    }
};

// Driver
int main() {
    Solution sol;

    vector<string> words1 = {"mass", "as", "hero", "superhero"};
    for (auto &s : sol.stringMatching(words1)) cout << s << " "; // as hero
    cout << endl;

    vector<string> words2 = {"leetcode", "et", "code"};
    for (auto &s : sol.stringMatching(words2)) cout << s << " "; // et code
    cout << endl;

    vector<string> words3 = {"blue", "green", "bu"};
    for (auto &s : sol.stringMatching(words3)) cout << s << " "; // (empty)
    cout << endl;

    return 0;
}
