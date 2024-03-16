### Code:

```cpp
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // Initialize two pointers i and j to track the subarray boundaries
        int i = 0, j = 0;
        // Initialize sum to track the current sum of elements in the subarray
        int sum = 0;
        // Initialize ans to store the number of subarrays with the sum equal to goal
        int ans = 0;

        // Set the initial value of sum to the first element of nums
        sum = nums[0];

        // Iterate through the array until either i or j reaches the end
        while (i < nums.size() && j < nums.size()) {
            // If the current sum equals the goal
            if (sum == goal) {
                // Increment ans since the current subarray has the desired sum
                ans++;
                // Move j to the next element and update sum
                j++;
                sum += nums[j];
            }
            // If the current sum exceeds the goal
            else if (sum > goal) {
                // Adjust sum by subtracting nums[i] from it
                sum -= nums[i];
                // Move i to the next element
                i++;
            }
            // If the current sum is less than the goal
            else {
                // Increment j to expand the subarray and update sum
                j++;
                sum += nums[j];
            }
        }

        // After the first loop, handle the case where i is less than nums.size() but sum is still equal to goal
        while (i < nums.size()) {
            // Subtract nums[i] from sum and move i to the next element
            sum -= nums[i++];
            // If sum becomes equal to goal, increment ans
            if (sum == goal) ans++;
        }

        // Return the total number of subarrays with sum equal to goal
        return ans;
    }
};
```

### Approach:

The given code calculates the number of subarrays in the given array `nums` with a sum equal to `goal`. It uses a two-pointer approach to traverse the array while maintaining the current sum.

1. Initialize two pointers `i` and `j` to the beginning of the array and set `sum` to the value of the first element of the array.
2. Iterate through the array while both pointers are within the array bounds.
   - If the current `sum` equals `goal`, increment the answer `ans` and move the `j` pointer to the next element to explore more subarrays.
   - If the `sum` exceeds `goal`, decrement `sum` by subtracting the value at `nums[i]` and move the `i` pointer to the next element.
   - If the `sum` is less than `goal`, increment the `j` pointer and update `sum` accordingly.
3. After the loop, handle the case where the `i` pointer is still within the array bounds but the `sum` is still equal to `goal`, updating the answer `ans` accordingly.

The final answer `ans` represents the number of subarrays with the sum equal to `goal`.

### Dry Run:

Given `nums = [1, 2, 3, 4]` and `goal = 3`.

| Iteration | `i` | `j` | `sum` | `ans`   | Action                         | Explanation                                                          |
| --------- | --- | --- | ----- | ------- | ------------------------------ | -------------------------------------------------------------------- |
| Initial   | 0   | 0   | 1     | 0       |                                |                                                                      |
| 1         | 0   | 1   | 3     | 1       | Increment `ans`                | Subarray [1, 2] has a sum of 3, so increment `ans`                   |
| 2         | 0   | 2   | 6     | 2       | Increment `ans`                | Subarray [1, 2, 3] has a sum of 6, so increment `ans`                |
| 3         | 1   | 2   | 5     | 3       | Decrement `sum`, Increment `i` | Subarray [2, 3] has a sum of 5, so decrement `sum` and increment `i` |
| 4         | 1   | 3   | 9     | 4       | Increment `ans`                | Subarray [2, 3, 4] has a sum of 9, so increment `ans`                |
| End       |     |     |       | Ans = 4 |                                |                                                                      |

**Final Answer:** The number of subarrays with the sum equal to `goal` is 4.
