## [235. Lowest Common Ancestor of a Binary Search Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/)

```cpp
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr; // if root is null , return null;

        // if Both p & q are smaller , then search in left
        if(p->val<root->val && q->val< root->val) return lowestCommonAncestor(root->left , p , q);
        // else if search in right:
        else if(p->val>root->val && q->val> root->val) return lowestCommonAncestor(root->right , p , q);
        // if p and  q are in different different nodes : then we are in ancestor node : simply return root :
        return root;
    }
};
```
