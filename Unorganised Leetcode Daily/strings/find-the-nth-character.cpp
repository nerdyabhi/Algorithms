char nthCharacter(string s, int r, int n)
{
    // code here

    for (int i = 0; i < r; i++)
    {
        string ans = "";
        for (int j = 0; j < s.length(); j++)
        {
            if (s[j] == '1')
                ans += "10";
            else
                ans += "01";
            if (ans.size() > n)
                break; // decreases time complexity  --> main logic is we don't bother much about the
                       // terms after n , we're  interested in nth term , so we won't compute the reast
                       // hence results in better time complexity
        }

        s = ans;
    }

    return s[n];
}