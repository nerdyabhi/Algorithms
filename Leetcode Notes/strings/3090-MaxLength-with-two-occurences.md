## 3090. Maximum Length Substring With Two Occurrences

```cpp
class Solution {
public:
    int maximumLengthSubstring(string s) {
        int arr[26] = {0};

        int i = 0, j = 0, n = s.length(), ans = 0;

            for(int j =0; j<n; j++)
            {
                arr[s[j]-'a']++;
                while(arr[s[j]-'a']>2)
                {
                    arr[s[i] -'a']--;
                    i++;

                }

                // cout<<"i : " << i << " , " << " , j :" << j <<" , ans : " <<ans<<endl;

                ans = max(ans , j-i+1);
            }
        return ans;
    }
};
```
