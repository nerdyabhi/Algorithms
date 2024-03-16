# Problem: Find Pivot Integer

## Problem Statement:
Given a positive integer `n`, find the pivot integer `x` such that the sum of all positive integers less than or equal to `x` is equal to the sum of all positive integers greater than `x` and less than or equal to `n`. If no such integer exists, return -1.

## Brute Force Approach:

### Approach Description:
1. Simply traverse until `n` and find the left sum using the formula:
   `leftSum = (i * (i + 1)) / 2`.

2. Find the right sum using:
   `rightSum = Total_sum - leftSum + i`.

3. If `leftSum == rightSum`, return `i`.

4. Else, return -1.

### Code:
```cpp
class Solution {
public:
    int pivotInteger(int n) {
        int Total_sum = n * (n + 1) / 2;
        for (int i = 1; i <= n; i++) {
            int leftSum = (i * (i + 1)) / 2;
            int rightSum = Total_sum - leftSum + i;

            if (leftSum == rightSum) return i;
        }

        return -1;
    }
};
```



#### Optimal Approach:

##### Basic Mathematical Approach:

- If the pivot is x, then the sum till x i.e. leftSum = x * (x + 1) / 2.
- The right sum is basically total_sum - leftsum + x.
- So for pivot element x, we have:
   `x * (x + 1) / 2 = n * (n + 1) / 2 - x * (x + 1) / 2 + x`.
- Solving it, we get:
   `x^2 = n * (n + 1) / 2`.
- Hence, x = sqrt(total_sum).

##### Code for O(1) Approach:

```cpp
class Solution {
public:
    int pivotInteger(int n) {
        int Total_sum = n * (n + 1) / 2;
        int pivot = sqrt(Total_sum);
        int ans = pow(pivot , 2) == Total_sum ? pivot : -1;
        return ans;
    }
};
