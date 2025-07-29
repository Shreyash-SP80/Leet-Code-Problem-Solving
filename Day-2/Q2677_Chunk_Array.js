

/*
🔢 LeetCode 2677. Chunk Array
🟢 Difficulty: Easy

📄 Description:
Given an array `arr` and a chunk size `size`, return a chunked array.

A chunked array contains the original elements in `arr`, but consists of subarrays 
(each of length `size`). The length of the last subarray may be less than `size` 
if `arr.length` is not evenly divisible by `size`.

⚠️ Note: Do not use lodash's _.chunk function.

📥 Input:
- arr = [1,2,3,4,5], size = 1
📤 Output:
- [[1],[2],[3],[4],[5]]

📥 Input:
- arr = [1,9,6,3,2], size = 3
📤 Output:
- [[1,9,6],[3,2]]

📥 Input:
- arr = [8,5,3,2,6], size = 6
📤 Output:
- [[8,5,3,2,6]]

📥 Input:
- arr = [], size = 1
📤 Output:
- []

🧠 Constraints:
- 0 <= arr.length <= 100
- 1 <= size <= arr.length (if arr is non-empty)
*/



/*
🧠 APPROACH: Chunk an array into subarrays of given size
1️⃣ Create an empty result array to store the final chunks.
2️⃣ Use a loop to go through the original array in steps of size.
3️⃣ For each step, extract a subarray from index i to i + size.
4️⃣ Add the subarray to the result array.
5️⃣ Repeat until all elements are processed.
📦 Edge Case: If the array is empty, return an empty array.
🧾 If elements don’t divide evenly, the last chunk will be smaller than size.
⏱️ Time Complexity: O(n)
📦 Space Complexity: O(n)
*/

var chunk = function(arr, size) {
    // This will hold the final chunked subarrays
    const result = [];

    // Loop over the array with a step of 'size'
    for (let i = 0; i < arr.length; i += size) {
        // Extract a portion of the array from index i to i + size (not including i + size)
        const subarray = arr.slice(i, i + size);

        // Push the subarray (chunk) into the result
        result.push(subarray);
    }

    // Return the final chunked array
    return result;
};

console.log(chunk([1, 2, 3, 4, 5], 2)); 
// Output: [[1, 2], [3, 4], [5]]

console.log(chunk([1, 9, 6, 3, 2], 3)); 
// Output: [[1, 9, 6], [3, 2]]

console.log(chunk([], 1)); 
// Output: []

console.log(chunk([8, 5, 3, 2, 6], 6)); 
// Output: [[8, 5, 3, 2, 6]]