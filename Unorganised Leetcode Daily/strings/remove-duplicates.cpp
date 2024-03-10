// gfg question

string removeDuplicates(string str)
{
    // code here
    unordered_map<char, int> mp;

    for (int i = 0; i < str.length(); i++)
    {
        mp[str[i]]++;
    }
    string ans = "";

    for (int i = 0; i < str.length(); i++)
    {
        if (mp[str[i]] >= 1)
            ans += str[i];
        mp[str[i]] = 0;
    }

    return ans;
}