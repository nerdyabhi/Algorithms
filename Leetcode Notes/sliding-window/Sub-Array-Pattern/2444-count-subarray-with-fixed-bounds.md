## [2444. Count Subarrays With Fixed Bounds](https://leetcode.com/problems/count-subarrays-with-fixed-bounds/)

```cpp
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {

       long long ans =0;
       int minKpos =-1 , maxKpos =-1 , culprit = -1;

       for(int i=0; i<nums.size(); i++)
       {
            if(nums[i] == minK)  minKpos = i;
            if(nums[i] == maxK) maxKpos = i;
            if(nums[i] < minK || nums[i] > maxK) culprit = i;

            long long index = min(minKpos , maxKpos);
            long long temp = index - culprit;
            ans+=temp<=0?0: temp;

       }
       return ans;
    }
};
```
