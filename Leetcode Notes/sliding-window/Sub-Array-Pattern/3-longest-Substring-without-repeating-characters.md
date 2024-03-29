### [3. Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/description/)

---

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       unordered_map<int ,int>mp;

       int i=0 , ans=0;
    // just traditional sliding window approach and nothing extra :
       for(int j=0; j<s.length(); j++)
       {
            mp[s[j]]++;

            while(i < s.length() && mp[s[j]] > 1)
            {
                mp[s[i]]--;
                i++;
            }

            ans = max(ans , j-i+1);
       }

       return ans;
    }


};
```
