## [450. Delete Node in a BST](https://leetcode.com/problems/delete-node-in-a-bst/description/)

- `Code with time complexity O(n)`

```cpp
class Solution {
public:

    TreeNode* deleteNode(TreeNode* &root, int key) {
        if (!root) return nullptr;

        if (root->val > key) {
            // search in left
            root->left = deleteNode(root->left, key);
        } else if (root->val < key) {
            // search in right
            root->right = deleteNode(root->right, key);
        } else {

            if(!root->left && !root->right) return NULL;
           if (!root->left) return root->right;

            else if (!root->right)  return root->left;

            else {
                // tree have both the child :
                // find largest value in left or min value in right of node :
                TreeNode* minValueNode = root->left;
                while (minValueNode->right) minValueNode = minValueNode->right;
                root->val = minValueNode->val;
                root->left = deleteNode(root->left, minValueNode->val);
            }
        }
        return root;
    }
};
```
