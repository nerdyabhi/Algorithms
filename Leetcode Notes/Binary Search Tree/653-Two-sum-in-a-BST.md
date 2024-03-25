## [653. Two Sum IV - Input is a BST](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/)

```cpp

class Solution {
public:
    void get_inorder(vector<int>&inorder , TreeNode* root)
    {
        if(!root) return;
        get_inorder(inorder , root->left);
        inorder.push_back(root->val);
        get_inorder(inorder , root->right);
    }
    bool findTarget(TreeNode* root, int k) {

        // easy approach : find inorder and store it in an array
        // - now simply check if there's two sum available using 2 pointers approach : ez laif
        vector<int> inorder;
        get_inorder(inorder , root );
        int i=0 , j=inorder.size()-1;
        while(i<j)
        {
            int sum = inorder[i] + inorder[j];
            if(sum == k) return true;
            else if(sum > k) j--;
            else i++;
        }
        return false;
    }
};
```
