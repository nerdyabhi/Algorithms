
class Solution
{
public:
    int solve(TreeNode *root, int sum)
    {
        if (!root)
            return 0;
        sum = (sum * 10) + root->val;
        if (!root->left && !root->right)
            return sum;
        int left = solve(root->left, sum);
        int right = solve(root->right, sum);

        return left + right;
    }
    int sumNumbers(TreeNode *root)
    {
        int sum = root->val;
        if (!root->left && !root->right)
            return sum;
        int left = solve(root->left, sum);
        int right = solve(root->right, sum);
        return left + right;
    }
};