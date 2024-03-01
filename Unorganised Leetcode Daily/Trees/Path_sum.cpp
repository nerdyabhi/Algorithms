class Solution
{

    // did inorder traversal and at leaf node checked if sum == targetSUm #ezPeasy
public:
    bool solve(TreeNode *root, int sum, int targetSum)
    {
        if (!root)
            return false;
        sum += root->val;
        if (!root->left && !root->right)
            return sum == targetSum;

        return solve(root->left, sum, targetSum) || solve(root->right, sum, targetSum);
    }
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        return solve(root, 0, targetSum);
    }
};