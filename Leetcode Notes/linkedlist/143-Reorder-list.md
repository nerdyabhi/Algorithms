### 143. Reorder list

<hr>
```cpp
class Solution {
public:
    void reorderList(ListNode* head) {
        // store nodes in a stack (we can access them in reverse order)

        stack<ListNode*>stck;
        ListNode*p = head;
        while(p)
        {
            stck.push(p); // store the nodes in a stack to access them in reverse order
            p = p->next;
        }

        int n =stck.size()/2; // we need half of the stack to proceed ez
        p = head; // initialise with head pointer to iterate
        ListNode* next=head , *top;
        while(n--)
        {
            top = stck.top(); stck.pop(); // basic logic can be understood by drawing and dry-run
            next = p->next;
            p->next = top;
            top->next = next;
            p = next;
        }
        next->next = NULL; // to take care of cycle
        /* note take care of  next=head as without this it may cause an error if there's only one element */

        return ;

    }
};
```

<hr>

<marquee> copyright @ abhi sharma</marquee>
