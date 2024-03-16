class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        unordered_map<int, int> mp; // Use unordered_map to store the running sum and its index.

        int sum = 0, ans = 0; // Initialize variables for sum and max length of subarray.
        mp[0] = -1;           // Start with sum 0 at index -1.

        for (int i = 0; i < nums.size(); i++) // Iterate through the array.
        {
            if (nums[i] == 0)
                sum += -1; // If the element is 0, subtract 1 from the sum.
            else
                sum += 1; // If the element is 1, add 1 to the sum.

            if (mp.find(sum) != mp.end())    // If the current sum has been seen before.
                ans = max(ans, i - mp[sum]); // Update the maximum length of subarray if necessary.
            else
                mp[sum] = i; // Otherwise, store the current sum and its index.
        }

        return ans; // Return the maximum length of balanced subarray.
    }
};
