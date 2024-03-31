### [Merge K sorted Arrays BruteForce](https://www.geeksforgeeks.org/problems/merge-k-sorted-arrays/1)

```cpp
vector<int> merge(vector<int>left , vector<int>right)
    {
        int i=0 , j=0;
        vector<int>ans;
        while(i<left.size() && j <right.size())
        {
            if(left[i] > right[j]) ans.push_back(right[j++]);
            else ans.push_back(left[i++]);
        }
        
        while(i<left.size()) ans.push_back(left[i++]);
        while(j<right.size()) ans.push_back(right[j++]);
        
        return ans;
    }
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        
        vector<int> ans = arr[0];
        for(int i=1; i<K; i++)
        {
            ans = merge(ans ,arr[i]);
        }
        
        return ans;
    }
```

- this can be optimized using heaps