## [98. Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/description/)

<hr>

### `Code block`

```cpp

class Solution {
public:

    bool solve(TreeNode* &root , long  min , long max)
    {
        if(!root) return true;
        if(root->val <= min || root->val >= max) return false;
        return solve(root->right , root->val , max) && solve(root->left , min , root->val);
    }
    bool isValidBST(TreeNode* root) {
        // simple approach
        // assign each node with it's upper and lower bound : if its' smalleer than it's lower bound it's simply not a valid bst
        // or it have a value greater than it's upper bound it's not A VALID BST (upper bound and lower bound is decided by all yourself)
        return solve(root , LONG_MIN , LONG_MAX);
    }
};
```

- Another approach can be : find inorder traversal and if it's not sorted : it's not a valid BST
