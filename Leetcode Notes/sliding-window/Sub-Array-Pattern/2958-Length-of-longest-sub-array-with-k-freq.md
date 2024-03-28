## [2958. Length of Longest Subarray With at Most K Frequency](https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/description/?envType=daily-question&envId=2024-03-28)

```cpp
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int , int>freq;
        int ans =0;
        int i=0;
        for(int j =0; j<nums.size(); j++) // traditional sliding window approach
        {
            freq[nums[j]]++; // store frequency
            while(freq[nums[j]] > k) // if freq > k , move window to right
            {
                freq[nums[i]]--;
                i++;
            }

            if(freq[nums[j]] <=k)
            {
                ans = max(ans , j-i+1); // else check the largest subaraay and we are good to go
            }
        }

        return ans; // nais
    }
};
```
