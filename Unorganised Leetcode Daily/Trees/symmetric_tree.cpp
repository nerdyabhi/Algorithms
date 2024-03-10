/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 // https://leetcode.com/problems/symmetric-tree/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:

    // More like a preorder Approach
    bool solve(TreeNode* left , TreeNode* right)
    {
        if(!left || !right) return left == right;
        // if left is null and right is not it will result in false

        if(left->val != right->val) return false; 
        // if value isn't same it'll still result in false;

        bool l = solve(left->left , right->right); // it'll traverse 
        bool r = solve(left->right , right->left);// check images given for better understanding 
        return l && r ;

    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
       return solve(root->left , root->right);

    }
};