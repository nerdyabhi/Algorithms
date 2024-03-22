## 234. Palindrome Linked List

```cpp
class Solution {
public:
ListNode* reverse(ListNode* &head)
{
    ListNode* old = NULL, *p = head, *next;

    while (p != NULL)
    {
        next = p->next;
        p->next = old;
        old = p;
        p = next;
    }

    return old;
}


    bool isPalindrome(ListNode* head) {

        ListNode *slow = head , *fast = head;
        while(fast!=NULL)
        {
            fast = fast->next;
            if(fast!=NULL)
            {
                fast = fast->next;
                slow = slow ->next;
            }
        }

        ListNode* reversed = reverse(slow);
        // slow ->next = reversed;
        ListNode*p1 = head , *p2 = reversed;


        while(p2!=NULL)
        {
            if(p1->val!= p2->val) return false;

            else
            {
                p1 = p1->next;
                p2 = p2->next;
            }

        }

        return true;

    }
};
```
