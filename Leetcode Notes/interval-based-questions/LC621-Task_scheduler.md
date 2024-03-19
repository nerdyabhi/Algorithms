## Code :

<hr>

```cpp
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0};

        for(int i=0 ;i<tasks.size(); i++){
            freq[tasks[i] - 'A']++;
        }
        sort(begin(freq) , end(freq));
        int chunk = freq[25] - 1;
        int idle = chunk * n;

        for(int i=24; i>=0; i--){
            idle -= min(chunk,freq[i]);
        }
        if(idle <0) idle = 0;
        return tasks.size() + idle;
    }
};
```
