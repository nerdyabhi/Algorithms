class Solution
{
public:
    int chocolateDistribution(int N, int M, vector<int> &arr, vector<int> &brr)
    {
        // code here
        int ans = 0;
        // int limit = min(N, M);

        sort(arr.begin(), arr.end());
        sort(brr.begin(), brr.end());

        int i = 0, j = 0;

        while (i < N && j < M)
        {
            if (arr[i] <= brr[j])
                i++, j++, ans++;
            else
                j++;
        }
        return ans;
    }
};