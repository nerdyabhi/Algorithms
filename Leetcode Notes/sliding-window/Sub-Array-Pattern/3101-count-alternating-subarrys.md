### 3101. Count Alternating Subarrays

```cpp
class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {

        long long i=0 , j=0 , ans=0;

        for(int j=0; j<nums.size();j++)
        {

            if(j>0 && nums[j] == nums[j-1]) i =j;

            ans+= j-i+1;

        }

        return ans;

    }
};
```
