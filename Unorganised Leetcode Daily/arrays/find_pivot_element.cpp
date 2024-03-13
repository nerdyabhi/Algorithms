class Solution
{
public:
    int pivotInteger(int n)
    {
        int Total_sum = n * (n + 1) / 2;
        int pivot = sqrt(Total_sum);
        int ans = pow(pivot, 2) == Total_sum ? pivot : -1;
        return ans;
    }
};