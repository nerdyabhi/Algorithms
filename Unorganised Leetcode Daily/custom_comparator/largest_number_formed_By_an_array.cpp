
bool myComp(string &s1, string &s2)
{
    string concat1 = s1 + s2;
    string concat2 = s2 + s1;
    return concat1 > concat2;
}

class Solution
{
public:
    string printLargest(int n, vector<string> &arr)
    {
        // code here
        string ans;

        sort(arr.begin(), arr.end(), myComp);

        for (int i = 0; i < arr.size(); i++)
        {
            ans += arr[i];
        }

        return ans;
    }
};