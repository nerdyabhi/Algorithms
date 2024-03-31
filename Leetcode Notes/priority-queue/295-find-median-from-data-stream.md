### [295. Find Median from Data Stream](https://leetcode.com/problems/find-median-from-data-stream/description/)

```cpp
class MedianFinder {
public:
    priority_queue<int>left; // left max heap to store first half of elements
    priority_queue<int, vector<int> , greater<int>>right; // right max heap to store second half of elements
    MedianFinder() {

    }

    void addNum(int num) {
        if(left.empty() || num < left.top()) left.push(num);
        else right.push(num);

        if(abs((int)left.size() - (int)right.size()) > 1)
        {
            right.push(left.top()); left.pop();
        }

        else if(left.size() < right.size())
        {
            left.push(right.top()); right.pop();
        }
    }

    double findMedian() {
        if(left.size() == right.size())
        return (double)(left.top() + right.top())/2;

        else return (double)left.top();

    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
```
