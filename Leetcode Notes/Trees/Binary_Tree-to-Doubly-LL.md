## [Binary Tree to linkedlist](https://www.geeksforgeeks.org/problems/binary-tree-to-dll/1)

```cpp
void solve(Node* root , Node* &head , Node* &prev)
    {
        if(!root) return ;
        solve(root->left , head , prev);
        if(!prev) head = root;
        else
        {
            prev->right = root;
            root->left = prev; // Update left pointer of the current node
        }
        prev = root;
        solve(root->right , head, prev);
        return;
    }


    Node * bToDLL(Node *root)
    {
        // your code here
        Node* head = NULL , *prev = NULL;
        if(!root) return NULL;

        solve(root , head , prev);
        return head;
    }
```
