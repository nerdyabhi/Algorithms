class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int power)
    {
        if (tokens.size() < 1)
            return 0;
        sort(tokens.begin(), tokens.end());
        int ans = 0;
        int i = 0, j = tokens.size() - 1;
        int max_score = 0;
        while (i <= j)
        {
            if (power >= tokens[i])
            {
                power -= tokens[i];
                ans++;
                i++;
            }

            else
            {
                if (ans > 0)
                {
                    power += tokens[j];
                    ans--;
                    j--;
                }

                else
                    return max_score;
            }
            max_score = max(ans, max_score);
        }

        return max_score;
    }
};