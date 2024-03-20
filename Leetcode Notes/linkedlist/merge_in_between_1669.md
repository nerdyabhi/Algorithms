### Merge in between Linkedlist Leetcode 1669

<marquee>
Here is the code -> abhi sharma (it feels amazing to swing like this) i go left , i go right hehe
</marquee>

```cpp
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {

        ListNode* start = list1 , *end = list1 , *p = list1;
        for(int i=1; i <=b;i++)
        {
            if(i==a) start = p;
            p = p->next;
        }
        end = p;

        start->next = list2;

        while(list2->next) list2 = list2->next;
        list2->next = end->next;

        return list1;
    }
};
```
