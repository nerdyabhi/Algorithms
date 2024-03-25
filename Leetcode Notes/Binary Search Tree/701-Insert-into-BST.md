## [701. Insert into a Binary Search Tree](https://leetcode.com/problems/insert-into-a-binary-search-tree/description/)

## Code block : O(log n ) space complexity

```cpp

class Solution {
public:

    TreeNode* insertIntoBST(TreeNode* root, int val) {
       if(!root)
       {
            root = new TreeNode(val);
            return root;
       }

       else if(root->val > val) root->left =  insertIntoBST(root->left ,val);
       else  root->right = insertIntoBST(root->right , val);
       return root;
    }
};
```
