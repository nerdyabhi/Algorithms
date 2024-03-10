class Solution
{
public:
    int minimumBoxes(vector<int> &apple, vector<int> &capacity)
    {
        int sum = 0;

        for (int i = 0; i < apple.size(); i++)
        {
            sum += apple[i];
        }

        sort(capacity.begin(), capacity.end());
        int ans = 0;

        for (int i = capacity.size() - 1; i >= 0; i--)
        {
            if (sum <= 0)
                return ans;

            sum -= capacity[i];
            ans++;
        }
        return ans;
    }
};