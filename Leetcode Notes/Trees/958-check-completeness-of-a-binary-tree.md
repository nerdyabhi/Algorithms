## [check-completeness-of-a-binary-tree](https://leetcode.com/problems/check-completeness-of-a-binary-tree/)

```cpp

class Solution {
public:

    int count(TreeNode* root)
    {
        if(!root) return 0;
        return 1 + count(root->left) + count(root->right);
    }

    bool solve(TreeNode* root ,int n , int index)
    {
        if(!root) return true;
        if(index>=n) return false;

        return solve(root->left , n , 2*index+1) && solve(root->right , n , 2*index+2);
    }
    bool isCompleteTree(TreeNode* root) {
        if(!root) return true;
        int n= count(root);
        return solve(root , n ,0);
    }
};

```
