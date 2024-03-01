class Solution
{
public:
    string maximumOddBinaryNumber(string s)
    {

        int ones = 0;
        int n = s.length();
        for (int i = 0; i < n; i++)
            if (s[i] == '1')
                ones++;
        string ans = string(ones - 1, '1') + string(n - ones, '0') + "1";
        return ans;
    }
};