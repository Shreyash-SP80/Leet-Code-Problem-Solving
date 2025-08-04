#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


/*
📘 Problem: 904. Fruit Into Baskets
-----------------------------------
You are visiting a farm with a row of fruit trees represented by an integer array `fruits` where `fruits[i]` is the type of fruit the i-th tree produces.

You have two baskets, each can only hold **one type** of fruit. You must pick exactly **one fruit from each tree** starting from any position and moving **right**. 

Your goal is to pick the **maximum number of fruits** that follow the rules.

🔸 Constraints:
- You can only carry **2 types** of fruits at most.
- Once you reach a third fruit type, you must **stop**.

🔹 Example:
Input: fruits = [1,2,3,2,2]  
Output: 4  
Explanation: You can pick from trees [2,3,2,2]

-----------------------------------------------------------------
🧠 Approach:
We use a sliding window approach with a hash map (unordered_map) to track fruit types.

1. Traverse the `fruits` array using a right pointer (`i`).
2. Count the frequency of each fruit using a map.
3. If the map has more than 2 fruit types, move the left pointer (`left`) to reduce the window size until only 2 types remain.
4. Keep track of the maximum size of the window (i.e., the max number of fruits we can collect).
*/



class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> check;  // map to count frequency of fruit types
        int n = fruits.size();
        int left = 0, maxfruit = 0;

        for (int i = 0; i < n; i++) {
            check[fruits[i]]++;  // add current fruit to map

            // if more than 2 types, shrink window from left
            while (check.size() > 2) {
                check[fruits[left]]--;
                if (check[fruits[left]] == 0) {
                    check.erase(fruits[left]);
                }
                left++;  // move left pointer
            }

            // update maximum window size
            maxfruit = max(maxfruit, i - left + 1);
        }

        return maxfruit;
    }
};

// 🔹 Main Function to Test the Code
int main() {
    Solution s;
    
    vector<int> fruits1 = {1, 2, 1};
    cout << "Output 1: " << s.totalFruit(fruits1) << endl;  // Output: 3

    vector<int> fruits2 = {0, 1, 2, 2};
    cout << "Output 2: " << s.totalFruit(fruits2) << endl;  // Output: 3

    vector<int> fruits3 = {1, 2, 3, 2, 2};
    cout << "Output 3: " << s.totalFruit(fruits3) << endl;  // Output: 4

    vector<int> fruits4 = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
    cout << "Output 4: " << s.totalFruit(fruits4) << endl;  // Output: 5

    return 0;
}
