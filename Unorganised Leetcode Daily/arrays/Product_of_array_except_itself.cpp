class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        int sum =1;
        for(int i=0; i<n; i++)
        {
            // calculate the left multiplaction
            ans[i] = sum;
            sum*=nums[i];
        }
        sum =1;
        for(int i=n-1; i>=0; i--)
        {
            // multiply it with right multiplication
            ans[i] *= sum;
            sum*=nums[i];
        }
       //ez laif

        return ans;

    }
};