class Solution
{
public:
    int maxFrequencyElements(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        int max = -1, count = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
            if (mp[nums[i]] > max)
            {
                max = mp[nums[i]];
                count = 0;
            }
            if (max == mp[nums[i]])
                count++;
        }

        ;
        return max * count;
    }
};