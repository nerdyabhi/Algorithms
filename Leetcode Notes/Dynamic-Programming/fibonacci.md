## [509. Fibonacci Number](https://leetcode.com/problems/fibonacci-number/description/)

```cpp
class Solution {
public:
    int solve(int n , vector<int>&dp)
    {
        if(n==0 || n==1) return n;
        if(dp[n] !=-1) return dp[n];

        dp[n] = solve(n-1 , dp) + solve(n-2 , dp);
        return dp[n];
    }

    int fib(int n) {
      vector<int>dp(n+1 , -1);
       return solve(n , dp);
    }
};
```
