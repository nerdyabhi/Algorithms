## [713. Subarray Product Less Than K](https://leetcode.com/problems/subarray-product-less-than-k/description/?envType=daily-question&envId=2024-03-27)

```cpp
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        int ans =0  , product = 1;

        int i=0;
        for(int j =0; j<nums.size(); j++) // traditional sliding window approach
        {
            product*= nums[j];
            while(i<=j && product >=k) // take care of this condition :
            {
                product /= nums[i];
                i++;
            }
            ans+=(j-i+1); // formula to get subarrays within a given index

        }

        return ans;
    }

};
```

# learning :

- `j-i+1` gives no. of sub-arrays from index i to j :
