#### Video solution

![Click here for video explaintation](https://www.youtube.com/watch?v=XXaVIDIbUn4)

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

Used extra vector to perform operations which will cut insertion and deletion cost of previous code making it run in o(n)

```cpp
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
