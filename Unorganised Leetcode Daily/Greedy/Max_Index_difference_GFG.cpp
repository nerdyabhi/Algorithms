int maxIndexDiff(int arr[], int n)
{
    vector<int> left(n);
    vector<int> right(n);

    left[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        left[i] = min(arr[i], left[i - 1]);
    }

    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = max(arr[i], right[i + 1]);
    }

    int i = 0, j = 0;
    int ans = -1;

    while (i < n && j < n)
    {
        if (left[i] <= right[j])
        {
            ans = max(ans, j - i);
            j++;
        }
        else
        {
            i++;
        }
    }

    return ans;
}