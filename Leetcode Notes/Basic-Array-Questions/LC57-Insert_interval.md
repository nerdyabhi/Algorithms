#### Video solution

<iframe align = "center"  width="400" height="225" src="https://www.youtube.com/embed/XXaVIDIbUn4" title="Insert Interval | Brute Force | Optimal | Google | Apple | codestorywithMIK" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

#### TLE solution (bruteforce)

```cpp
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        int i=0;

        while(i<intervals.size())
        {
            if(intervals[i][1] < newInterval[0] ) i++;

            else if (intervals[i][0] > newInterval[1])
            {
                // insert and return
                intervals.insert(intervals.begin() +i , newInterval);
                return intervals;
            }

            else
            {
                // merge
                newInterval[0] = min(intervals[i][0] , newInterval[0]);
                newInterval[1] = max(intervals[i][1] , newInterval[1]);

                intervals.erase(intervals.begin() + i);

            }


        }

        intervals.push_back(newInterval);

        return intervals;
    }
};
```

## Optimal Solution

```
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        vector<vector<int>> ans;
        int i=0;

        while(i<intervals.size())
        {
            if(intervals[i][1] < newInterval[0] )
            {
                ans.push_back(intervals[i]);
                i++;
            }

            else if (intervals[i][0] > newInterval[1]) break;

            else
            {
                // merge
                newInterval[0] = min(intervals[i][0] , newInterval[0]);
                newInterval[1] = max(intervals[i][1] , newInterval[1]);
                i++;
            }
        }

        ans.push_back(newInterval);

        while(i<intervals.size()){
            ans.push_back(intervals[i++]);
        }

        return ans;
    }
};
```
