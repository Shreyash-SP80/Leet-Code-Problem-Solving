#include <iostream>
#include <vector>
using namespace std;


/*
====================================================================
Problem: 1441. Build an Array With Stack Operations
====================================================================
You are given an integer array target and an integer n.

You have an empty stack with two operations:
- "Push": pushes an integer to the top of the stack.
- "Pop": removes the integer on the top of the stack.

You also have a stream of integers in the range [1, n].

You need to:
- Use these two operations to build the target array from the bottom to the top of the stack.
- Follow the rules:
    1. If the stream is not empty, pick the next integer and push it.
    2. If the stack is not empty, you can pop the top.
    3. Stop once the stack equals the target array.

Return the list of operations. Multiple valid answers are allowed.

--------------------------------------------------------------------
Example 1:
Input: target = [1,3], n = 3
Output: ["Push","Push","Pop","Push"]

Example 2:
Input: target = [1,2,3], n = 3
Output: ["Push","Push","Push"]

Example 3:
Input: target = [1,2], n = 4
Output: ["Push","Push"]

--------------------------------------------------------------------
Approach:
1. Start with an index pointer i = 0 representing the last number processed from the stream.
2. For each number 'num' in target:
   - While i < num - 1:
       Add "Push" then "Pop" to the operations (to skip numbers not in target).
       Increment i.
   - Add "Push" for the current 'num'.
   - Increment i.
3. Return the operations list.

--------------------------------------------------------------------
Complexity:
- Time Complexity: O(n)  
  We process each number at most once.
- Space Complexity: O(1) extra space apart from the output list.
====================================================================
*/



class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int i = 0; // Last processed number from the stream
        
        for (int num : target) {
            while (i < num - 1) {
                ans.push_back("Push");
                ans.push_back("Pop"); // skip this number
                i++;
            }
            ans.push_back("Push");
            i++;
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> target1 = {1, 3};
    int n1 = 3;
    auto res1 = sol.buildArray(target1, n1);
    cout << "Example 1 Output: ";
    for (auto &op : res1) cout << op << " ";
    cout << endl;

    vector<int> target2 = {1, 2, 3};
    int n2 = 3;
    auto res2 = sol.buildArray(target2, n2);
    cout << "Example 2 Output: ";
    for (auto &op : res2) cout << op << " ";
    cout << endl;

    vector<int> target3 = {1, 2};
    int n3 = 4;
    auto res3 = sol.buildArray(target3, n3);
    cout << "Example 3 Output: ";
    for (auto &op : res3) cout << op << " ";
    cout << endl;

    return 0;
}
