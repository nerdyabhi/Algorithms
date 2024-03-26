## [41. First Missing Positive](https://leetcode.com/problems/first-missing-positive/description/?envType=daily-question&envId=2024-03-26)

<hr>

```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {


        // intituion is very simple (we just need numbers from 1 to n)
        // (as we are avoiding -ve numbers and numbers greater than 1)
        int n = nums.size();
        bool is_one = false; // a flag to check if 1 is present in array or not

        for(int i=0; i<n; i++)
        {
            int num = nums[i];
            if(num >n || num<=0) nums[i] = 1; // if num[i] is greater than one or smaller than 1 turn it into 1;
            if(num == 1) is_one = true; // if one is present mark flag as true
        }

        if(!is_one) return 1; // if one is not present , then ofc the smallest missing postive is 1

        for(int i=0; i<n; i++)
        {
            int index = abs(nums[i])-1; // now iterate over the array using index ( index - 1 , as it's 0-based indexing in array)
            if(nums[index] > 0 ) nums[index] *=-1; // mark the numbers negative if visited (ignore the negative numbers )
        }

        for(int i=0; i<n; i++) // iterate again to check if any positive number is left
        {
            if(nums[i] >0) return i+1; // if any +ve numbers is found : that means we haven't found (i+1 num in previous iteration to mark it negative)
        }

        return n+1; // if every number from 1 to n is found , so the answer now is n +1 :
    }
};
```

### Video explaination :

[Click here](https://youtu.be/lyjOwaUEWWQ?list=RDCMUCaw58edcO3ZqMw76Bvs0kGQ)
