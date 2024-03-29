## [Merge two binary max heaps](https://www.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/)

```cpp
void  heapify(vector<int> &arr , int n , int i )
    {
        int left = 2*i+1;
        int right = 2*i+2;
        int largest = i;

        if(left <n && arr[left] > arr[largest]) largest = left;
        if(right <n && arr[right] > arr[largest]) largest = right;
        if(largest !=i)
        {
            swap(arr[i] , arr[largest]);
            heapify(arr , n , largest);
        }

    }

    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
            vector<int> ans(n+m);
            int k=0;
            for(int i=0; i<n; i++) ans[k++] = a[i];
            for(int i=0; i<m; i++) ans[k++] = b[i];

            int size = ans.size();
            for(int i=size/2-1; i>=0; i--)
            heapify(ans , size , i);
            return ans;

    }

```
