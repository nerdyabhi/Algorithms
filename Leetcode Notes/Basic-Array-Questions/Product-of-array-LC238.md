#### Approach Explanation:

- The code calculates the product of all elements except self in an input array using two passes.
- In the first pass, it calculates the product of all elements to the left of each element.
- In the second pass, it multiplies the products of left elements with the products of right elements to get the final result.

**Time Complexity:**

- The time complexity of this approach is O(n), where n is the size of the input array. This is because the code iterates through the array twice.

**Space Complexity:**

- The space complexity is O(n), as the vector `ans` of size n is used to store the result.

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int left_product = 1; // Initialize left_product to 1

        // Calculate the product of elements to the left of each element
        for(int i = 0; i < n; i++) {
            ans[i] = left_product; // Store left_product in ans[i]
            left_product *= nums[i]; // Update left_product for next iteration
        }

        int right_product = 1; // Initialize right_product to 1

        // Multiply the product of elements to the right of each element with ans[i]
        for(int i = n - 1; i >= 0; i--) {
            ans[i] *= right_product; // Multiply ans[i] with right_product
            right_product *= nums[i]; // Update right_product for next iteration
        }

        return ans; // Return the final product array
    }
};
```

### Dry Run on nums = [1, 2, 3, 4]

| Iteration | Element | Left Product | Right Product | Action                    | Explanation                          | Updated Array  |
| --------- | ------- | ------------ | ------------- | ------------------------- | ------------------------------------ | -------------- |
| Initial   | values  | [0, 0, 0, 0] |               |                           |                                      |                |
| 1         | 1       | 1            | 1             | Left product calculation  | Store left product of 1 (1)          | [1, 0, 0, 0]   |
| 2         | 2       | 1            | 4             | Left product calculation  | Store left product of 1, 2 (1)       | [1, 1, 0, 0]   |
| 3         | 3       | 2            | 12            | Left product calculation  | Store left product of 1, 2, 3 (2)    | [1, 1, 2, 0]   |
| 4         | 4       | 6            | 24            | Left product calculation  | Store left product of 1, 2, 3, 4 (6) | [1, 1, 2, 6]   |
|           |         |              |               | Right product calculation | Multiply right product with ans[i]   | [24, 12, 8, 6] |

**Final array:** Final product array = [24, 12, 8, 6]

**Result:** The product array except self is [24, 12, 8, 6].
