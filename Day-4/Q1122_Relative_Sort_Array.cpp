#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm> 
using namespace std;


/*
--------------------------------------------
LeetCode Problem 1122: Relative Sort Array
Difficulty: Easy
--------------------------------------------

📝 Problem Statement:
Given two arrays arr1 and arr2, where:
- The elements of arr2 are distinct.
- All elements in arr2 are also present in arr1.

Sort the elements of arr1 such that:
1. The relative ordering of items in arr1 is the same as in arr2.
2. Elements not present in arr2 should be placed at the end of arr1 in ascending order.

-----------------------------------------------------
🔒 Constraints:
- 1 <= arr1.length, arr2.length <= 1000
- 0 <= arr1[i], arr2[i] <= 1000
- All elements of arr2 are distinct
- Each element in arr2 is also in arr1

-----------------------------------------------------
📥 Example 1:
Input: 
    arr1 = [2,3,1,3,2,4,6,7,9,2,19]
    arr2 = [2,1,4,3,9,6]

Output: 
    [2,2,2,1,4,3,3,9,6,7,19]

📥 Example 2:
Input: 
    arr1 = [28,6,22,8,44,17]
    arr2 = [22,28,8,6]

Output: 
    [22,28,8,6,17,44]

------------------------------------------------------------
💡 Approach:
1. Count frequency of all elements in arr1 using a hash map (unordered_map).
2. For each element in arr2:
   - Append it to the result as many times as it appears in arr1.
   - Remove it from the frequency map.
3. For remaining elements (those not in arr2):
   - Add them to a temporary list.
   - Sort this list in ascending order.
4. Append the sorted remaining elements to the result.

------------------------------------------------------------
🔗 Source: https://leetcode.com/problems/relative-sort-array/
------------------------------------------------------------
*/


class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // std::unordered_map<KeyType, ValueType> map_name;   // #include <unordered_map> 
        // unordered_map<int, int> freq; creates a hash table (from the C++ Standard Library)that:
        // Maps a key of type int (e.g., a number from an array)
        // To a value of type int (e.g., its frequency/count)
        unordered_map<int, int> freq; // Hash map to count frequency of elements in arr1
        vector<int> result;

        // Count frequency of each element in arr1
        for (int i : arr1) {
            freq[i]++;
        }

        // Place elements from arr2 in the result in order
        for (int num : arr2) {
            while (freq[num]-- > 0) {
                result.push_back(num);
            }
            freq.erase(num); // Remove from map to avoid adding again later
        }

        // Now our task is collect remaining elements
        vector<int> rest;
        for (auto& pair : freq) {
            int key = pair.first;
            int value = pair.second;
            while (value--) {
                rest.push_back(key);
            }
        }

        // Sort the remaining elements in ascending order
        sort(rest.begin(), rest.end());

        // Append the sorted remaining elements to the result
        // vector.insert(position, range_start, range_end);
        result.insert(result.end(), rest.begin(), rest.end());

        return result;
    }
};

// Helper function to print the contents of a vector
void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

// Main function for testing
int main() {
    Solution sol;

    vector<int> arr1 = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
    vector<int> arr2 = {2, 1, 4, 3, 9, 6};

    vector<int> result = sol.relativeSortArray(arr1, arr2);

    cout << "Sorted Array: ";
    printVector(result);

    return 0;
}