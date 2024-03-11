class Solution
{
public:
    string customSortString(string order, string s)
    {
        int arr[26] = {0};
        // Not optimal approach but , theek hi hai ab achaar dalega itna

        auto Comparator = [order](char &a, char &b)
        {
            return order.find(a) < order.find(b);
        };

        sort(s.begin(), s.end(), Comparator);

        return s;
    }
};