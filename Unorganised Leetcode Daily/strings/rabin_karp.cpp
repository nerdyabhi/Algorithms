vector<int> search(string pat, string txt)
{
    // code here.
    vector<int> v;
    int found = txt.find(pat);
    while (found != string::npos)
    {
        // cout << "Pattern found at index " << found << endl;
        v.push_back(found + 1);
        found = txt.find(pat, found + 1);
    }
    return v;