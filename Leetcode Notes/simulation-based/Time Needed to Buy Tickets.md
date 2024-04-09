## [2073. Time Needed to Buy Tickets](https://leetcode.com/problems/time-needed-to-buy-tickets/?envType=daily-question&envId=2024-04-09)

### Intuition - (bruteforce)

- Make a queue Data Structure and store number with indexes :
  -Simulate the given problem and it's as easy as it seems

```cpp
class Solution {
public:
    int timeRequiredToBuy(vector<int>& arr, int k) {
        queue<pair<int, int>>q;
        for(int i =0; i<arr.size(); i++) q.push({arr[i] , i});

        int ans=0;
        while(arr[k] !=0)
        {
            auto it = q.front(); q.pop();
            int num  = it.first;
            int index = it.second;
            if(num >0)
            {
                num--;
                arr[index]--;
                ans++;
                if(num>0)
                q.push({num , index});
            }
        }

        return ans;
    }
};
```

- `time complexity : O(n*k)`
- `space complexity : O(n)`

## Approach -2 (don't use queue)

- Modify the array and simulate as follows :

```cpp
class Solution {
public:
    int timeRequiredToBuy(vector<int>& arr, int k) {
        int ans=0;
        while(arr[k] !=0)
        {
           for(int i=0; i<arr.size(); i++)
           {
                if(arr[i] >0)
                {
                    ans++;
                    arr[i]--;
                }
                if(arr[k] == 0) return ans;
           }
        }

        return ans;
    }
};
```

-`time complexity : O(n*k)` -`Space Complexity : O(1)`

### Approach -3 (most optimal one)

- Based on some observations :

```cpp
class Solution {
public:
    int timeRequiredToBuy(vector<int>& arr, int k) {
        int ans=0;
       for(int i=0; i<arr.size(); i++)
       {
            if(i<=k)
            ans+=min(arr[k] , arr[i]);
            else ans+= min(arr[k]-1 , arr[i]);

       }
        return ans;
    }
};
```

-`Time complexity : O(n)` -`Space Complexity : O(1)`
