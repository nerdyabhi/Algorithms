class Solution
{
public:
    int minimumLength(string s)
    {

        int n = s.length();
        if (n == 1)
            return 1;

        int i = 0, j = n - 1;

        while (i < j && s[i] == s[j])
        {
            char temp = s[i];
            while (i <= j && s[i] == temp)
            {
                i++;
                n--;
            }
            while (i <= j && s[j] == temp)
            {
                j--;
                n--;
            }
        }

        return n;
    }
};