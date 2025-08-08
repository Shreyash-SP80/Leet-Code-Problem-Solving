#include <iostream>
#include<vector>
using namespace std;

/*
----------------------------------------
Problem: 941. Valid Mountain Array
----------------------------------------
Given an array of integers arr, return true if and only if it is a valid mountain array.

A mountain array must satisfy:
1. arr.length >= 3
2. There exists some index i (0 < i < arr.length - 1) such that:
   - arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
   - arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

Example 1:
Input: arr = [2, 1]
Output: false

Example 2:
Input: arr = [3, 5, 5]
Output: false

Example 3:
Input: arr = [0, 3, 2, 1]
Output: true
----------------------------------------

Approach:
1. Check if array has at least 3 elements (minimum for mountain shape).
2. Traverse from start while elements are strictly increasing → find the peak.
3. The peak cannot be the first or last element (otherwise, it's not a mountain).
4. From the peak, traverse while elements are strictly decreasing.
5. If we reach the last index exactly after the decreasing part, it's a valid mountain.
----------------------------------------
*/

bool validMountainArray(vector<int>& arr) {
    int n = arr.size();
    if (n < 3) return false;

    int i = 0;
    // Step 1: Ascend until peak
    while (i + 1 < n && arr[i] < arr[i + 1]) i++;
    // Step 2: Peak can't be first or last
    if (i == 0 || i == n - 1) return false;
    // Step 3: Descend after peak
    while (i + 1 < n && arr[i] > arr[i + 1]) i++;
    // Step 4: Check if reached end
    return i == n - 1;

    // OR


    // int n = arr.size();
    // if (n < 3) return false; // Mountain needs at least 3 elements

    // int left = 0, right = 0;

    // for (int i = 1; i < n - 1; i++) {
    //     if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) { // peak found
    //         left = i - 1;
    //         right = i + 1;

    //         // Move left pointer backwards
    //         while (left > 0 && arr[left] > arr[left - 1]) {
    //             left--;
    //         }

    //         // Move right pointer forward
    //         while (right < n - 1 && arr[right] > arr[right + 1]) {
    //             right++;
    //         }

    //         // Check if both sides covered full array
    //         return (left == 0 && right == n - 1);
    //     }
    // }
    // return false; // No peak found
    
}

int main() {
    vector<int> arr1 = {2, 1};
    vector<int> arr2 = {3, 5, 5};
    vector<int> arr3 = {0, 3, 2, 1};

    cout << "Test case 1: " << (validMountainArray(arr1) ? "true" : "false") << endl;
    cout << "Test case 2: " << (validMountainArray(arr2) ? "true" : "false") << endl;
    cout << "Test case 3: " << (validMountainArray(arr3) ? "true" : "false") << endl;

    return 0;
}

/*
Expected Output:
Test case 1: false
Test case 2: false
Test case 3: true
*/
