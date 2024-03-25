## [108. Convert Sorted Array to Binary Search Tree](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/submissions/1213812420/)

```cpp

class Solution {
public:

/* very basic approach :
    inorder of a bst is sorted already : 1 , 2, 3, 4, 5
    now take the middle element and make a node out of it
      3
    /   \
(1 , 2)  (4  ,5)

now solve for those particular sub-array using recursion and we are good to go
*/

    TreeNode* solve(vector<int>&nums , int s , int e)
    {
        if(s>e) return NULL;
        int mid = s + (e-s)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = solve( nums , s , mid-1);
        root->right = solve( nums , mid + 1, e);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
      return solve(nums , 0 , nums.size()-1);
    }
};
```
