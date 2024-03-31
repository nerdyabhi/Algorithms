## [992. Subarrays with K Different Integers](https://leetcode.com/problems/subarrays-with-k-different-integers/)

```cpp
class Solution {
public:

    int solve(vector<int>& nums, int k)
    {
        unordered_map<int , int>mp;

        int i=0  , ans =0;
        for(int j=0; j<nums.size(); j++)
        {
            mp[nums[j]]++;

            while(mp.size()> k)
            {
                mp[nums[i]]--;
                if(mp[nums[i]] ==0) mp.erase(nums[i]);
                i++;
            }

            ans+= j-i+1;
        }

        return ans;
    }


    int subarraysWithKDistinct(vector<int>& nums, int k) {
        if(k==1) return solve(nums , k);
        int subarray1 = solve(nums , k); // will get subarrays with distnict elements <=k
        int subarray2 = solve(nums, k-1); // will get subaraays with distnict elements <=k-1

        /* suppose k = 3 , the traditional sliding window template will get us subarrays for k=1 , k=2 and k=3
          To get elements till k = 3 only , we can get subarrays for k = 1 and k =2 (we can use the same function to get so)

          now minus k=2 from k = 3 , we get our answer
        */

        return subarray1-subarray2;
    }
};

```
