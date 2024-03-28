## [1373. Maximum Sum BST in Binary Tree](https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/description/)

- Hard question : try to do it again , have crammed the answer only :
- can use vector instead of class as well

```cpp

class Solution {
public:

    class info
    {
        public:
        int maxi;
        int mini;
        int sum;
        bool isBST;
    };

    info solve(TreeNode* root , int &ans)
    {
        if(!root)
        {
            return {INT_MIN , INT_MAX , 0 , true};
        }

        info left = solve(root->left, ans);
        info right = solve(root->right, ans);

        info curr;

        curr.sum = left.sum + right.sum + root->val;
        curr.maxi = max(root->val , right.maxi);
        curr.mini = min(root->val , left.mini);

        if(left.isBST && right.isBST && (root->val > left.maxi && root->val < right.mini ))
        {
            curr.isBST = true;
        }

        else curr.isBST = false;

        if(curr.isBST)
        {
            ans = max(ans , curr.sum);
        }

        return curr;
    }

    int maxSumBST(TreeNode* root) {
        int ans = 0;
        info temp = solve(root , ans);
        return ans;
    }
};
```
