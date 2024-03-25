## 700. Search in a Binary Search Tree

- `just apply the basic binary search operation in recursive way and we are good to go :`

```cpp
class Solution {
public:

    TreeNode* solve(TreeNode* root , int val)
    {
        if(!root) return nullptr;
        if(root->val == val) return root;

        else if(root->val > val) return solve(root->left , val);
        else if(root->val < val) return solve(root->right , val);

        return nullptr;
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        return solve(root , val);
    }
};
```
