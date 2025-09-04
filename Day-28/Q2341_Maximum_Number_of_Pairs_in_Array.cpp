#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


/*
2341. Maximum Number of Pairs in Array
--------------------------------------
We are given an integer array nums. In one operation:
- Choose two equal integers and remove them as a pair.
- Repeat this until no more pairs can be formed.

We must return:
- answer[0] = number of pairs formed
- answer[1] = number of leftover elements
*/

/*
# Intuition
- Each pair is formed by two equal numbers.
- For each unique number:
  - Its frequency contributes `freq // 2` pairs.
  - Any remainder (`freq % 2`) contributes to leftover count.
- The total pairs = sum of all (freq // 2).
- The total leftovers = sum of all (freq % 2).

# Approach
1. Count frequency of each number using a hashmap.
2. For each frequency f:
   - Add f/2 to pairs.
   - Add f%2 to leftovers.
3. Return {pairs, leftovers}.

# Complexity
- Time: O(n) to count frequencies.
- Space: O(u) where u = number of unique elements.
*/


class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) freq[num]++;

        int pairs = 0, leftover = 0;
        for (auto &ele : freq) {
            pairs += ele.second / 2;
            leftover += ele.second % 2;
        }
        return {pairs, leftover};
    }
};

// Driver
int main() {
    Solution sol;

    vector<int> nums1 = {1,3,2,1,3,2,2};
    for (int x : sol.numberOfPairs(nums1)) cout << x << " "; // 3 1
    cout << endl;

    vector<int> nums2 = {1,1};
    for (int x : sol.numberOfPairs(nums2)) cout << x << " "; // 1 0
    cout << endl;

    vector<int> nums3 = {0};
    for (int x : sol.numberOfPairs(nums3)) cout << x << " "; // 0 1
    cout << endl;

    return 0;
}
