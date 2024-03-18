### CODE :

```cpp
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {

        sort(begin(points) , end(points));

        int count = 1;

        vector<int> prev = points[0];
        for(int i=1; i<points.size();i++ )
        {
            if(prev[1] < points[i][0])
            {
                // if previous's end point is smaller than  current's start point , so no overlapping
                count++; // we need one more arrow to shoot
                prev = points[i]; // replace previous with current;

            }

            else
            {
                // means overlapping is there


            /*
            1           5
             o-----------o (prev)
                   3 o-----------o 7 (current)

                   so the overlapping region here is (3,7)
                  overalapping region's starting point = max ( prev-start point , current -start -point);
                  overalapping region's end point = min ( prev-end point , current -end -point);

            */
                prev[0] = max(prev[0] , points[i][0]); // overlapping region is max of prev and current's
                prev[1] = min(prev[1] , points[i][1]);
            }
        }

        return count;
    }
};
```
