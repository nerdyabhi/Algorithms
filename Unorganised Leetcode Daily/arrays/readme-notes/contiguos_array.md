#### Approach Explanation:

- The code uses an unordered map to store the running sum of elements encountered so far and their corresponding indices.
- It iterates through the input array, adjusting the sum based on the current element (adding 1 for '1' and subtracting 1 for '0').
- If the sum has been seen before, it updates the maximum length of a balanced subarray.
- The maximum length of the balanced subarray is returned as the result.

**Time Complexity:**

- The time complexity of this approach is O(n), where n is the size of the input array. This is because the code iterates through the array once.

**Space Complexity:**

- The space complexity is also O(n), as the worst-case scenario is that all elements of the array are distinct and stored in the unordered map.

```C++ class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int , int> mp; // Use unordered_map to store the running sum and its index.

        int sum =0 , ans =0; // Initialize variables for sum and max length of subarray.
        mp[0] = -1; // Start with sum 0 at index -1.

        for(int i=0; i<nums.size(); i++) // Iterate through the array.
        {
            if(nums[i] == 0) sum+=-1; // If the element is 0, subtract 1 from the sum.
            else sum+=1; // If the element is 1, add 1 to the sum.

            if(mp.find(sum) != mp.end()) // If the current sum has been seen before.
                ans = max(ans ,i - mp[sum]); // Update the maximum length of subarray if necessary.
            else
                mp[sum] = i; // Otherwise, store the current sum and its index.

        }

        return ans; // Return the maximum length of balanced subarray.
    }
};
```

##### Dry Run on [0,0 ,1 , 0 , 0 , 1]

### Dry Run:

#### Dry Run on [0, 0, 1, 0, 0, 1]

| Iteration | Element | Sum | Action     | Explanation      | Map                     | Max Length |
| --------- | ------- | --- | ---------- | ---------------- | ----------------------- | ---------- |
| 0         | 0       | 0   | Add to map | Init sum 0 at -1 | `{0: -1}`               | 0          |
| 1         | 0       | -1  | Add to map | Update sum to -1 | `{0: -1, -1: 0}`        | 0          |
| 2         | 1       | 0   | Add to map | Update sum to 0  | `{0: -1, -1: 0}`        | 2          |
| 3         | 0       | -1  | Add to map | Update sum to -1 | `{0: -1, -1: 0}`        | 2          |
| 4         | 0       | -2  | Add to map | Update sum to -2 | `{0: -1, -1: 0, -2: 3}` | 2          |
| 5         | 1       | -1  | Add to map | Update sum to -1 | `{0: -1, -1: 0, -2: 3}` | 4          |

**Result:** The max length of the balanced subarray is 4.
