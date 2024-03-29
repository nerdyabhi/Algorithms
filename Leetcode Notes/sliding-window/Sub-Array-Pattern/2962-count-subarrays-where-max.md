## [2962. Count Subarrays Where Max Element Appears at Least K Times](https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/?envType=daily-question&envId=2024-03-29)

- Traditonal sliding window approach

```cpp
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {

        int i=0 , j=0 , n = nums.size() ,maxi = INT_MIN , freq =0;
        long long ans =0;
        for(int i=0; i<n; i++)  maxi = max(maxi , nums[i]); // get max element

        // normal sliding window approach

        for(j=0; j<n; j++)
        {
            if(nums[j] == maxi) freq++; // if max element found , freq++;

            /*           0 , 1 , 2, 3 , 4
               Input :  |1 , 3 , 2 , 3, 3 |

                at j=3, freq =k ;
                and we have 2 subarrays :or n-j subarrays
                if j tak freq >=k hai toh ofc j se n tak bhi freq >=k hi rahegi
                toh n-j total subarrays milenge :

                Ab i ko increment karo :
                i = 1 par bhi 2 sub array milenge :) i.e n-j


            */

            while(freq >=k) //
            {
                ans += n-j;
                if(nums[i] == maxi) freq--;
                i++;
            }

            /*
                    j  : 3 i :0 ans : 2
                    j  : 3 i :1 ans : 4
                    j  : 4 i :2 ans : 5
                    j  : 4 i :3 ans : 6
            */
        }

       return ans;
    }
};
```
