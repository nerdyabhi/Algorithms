### Heap sort :

-Best case: `O(n log n)` <br>
-Worst case: `O(n log n)`<br>
-Average case: `O(n log n)` <br>

---

## CODE BLOCK

```cpp

class Solution {
public:

// heap sort algorithm :
void heapify(vector<int>&arr, int n, int i) // program for heapify
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;

    if (left < n && arr[left] >= arr[largest])
        largest = left;
    if (right < n && arr[right] >= arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        for(int i=n/2-1; i>=0; i--) heapify(nums , n , i); // build heap

        while(n>0) // heap sort
        {
            n--;
            swap(nums[0] , nums[n]);
            heapify(nums , n , 0);
        }

        return nums;
    }
};
```
