## 117. Populating Next Right Pointers in Each Node II

### Bruteforce approach O(n)

- Level order traversal

```cpp
class Solution {
public:
    Node* connect(Node* root) {

        // level order traversal and do it's work
        // Bruteforce approach -> ez hai
        if(!root) return nullptr;
        queue<Node*>q;
        q.push(root);
        q.push(NULL);

        while(!q.empty())
        {
           Node*temp = q.front(); q.pop();
           if(!temp)
           {
                if(!q.empty())q.push(NULL);
           }

           else
           {
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
            temp->next = q.front();
           }


        }
        return root;
    }
};
```
