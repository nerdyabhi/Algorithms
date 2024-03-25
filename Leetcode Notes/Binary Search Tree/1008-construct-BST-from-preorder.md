## 1008. Construct Binary Search Tree from Preorder Traversal

- `Very simple approach : `

```cpp
class Solution {
public:

    void solve(TreeNode* &root , int data)
    {

        if(!root)
        {
            root = new TreeNode(data);
            return;
        }

        if(data < root->val)
        {
            solve(root->left , data);
        }

        else
        {
           solve(root->right , data);

        }
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index =0;
        TreeNode* root = new TreeNode(preorder[0]);

        for(int i=1; i<preorder.size();i++)
        {
          solve(root  , preorder[i]);
        }
        return root;
    }
};
```
