## [Sorted Linked List to BST ](https://www.geeksforgeeks.org/problems/sorted-list-to-bst/0)

- Hard question : practice it again someday

```cpp
class Solution{
  public:
 TNode* solve(LNode* &head, int n) {
    if (n <= 0 || !head) return NULL;

    int leftSize = n - 1 - n/2; // Calculate the size of the left subtree
    TNode* leftSubTree = solve(head, n/2); // Solve for the left subtree

    TNode* root = new TNode(head->data); // Create node for the current root
    root->left = leftSubTree; // Attach the left subtree to the root

    head = head->next; // Move the head pointer to the next element

    root->right = solve(head, leftSize); // Solve for the right subtree
    return root;
}

TNode* sortedListToBST(LNode* head) {
    int n = 0;
    LNode* p = head;
    while (p) {
        p = p->next;
        n++;
    }
    return solve(head, n);
}

};
```
