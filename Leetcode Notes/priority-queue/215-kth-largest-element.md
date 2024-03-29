## [215. Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/description/)

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int , vector<int> , greater<int>>pq; // used priority queue as a min-heap

        for(int i=0; i<k; i++) pq.push(nums[i]);  // fill upto k elements in min-heap ()
        for(int i=k; i<nums.size(); i++)
        {
            if(nums[i] > pq.top()) // continuosly remove the smaller elements
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }

        return pq.top(); // now it's a min-heap & have k elements , ofc the top element is the smallest
        // and from the loop we put the greatest k elements in pq;
        // where the top element is minimum of those greatest k  , hence we got our answer
    }
};

```
