
class Solution
{
public:
    int solve(TreeNode *root, int sum)
    {
        if (!root)
            return 0;                 // If No root -> simply return without making anychanges in sum
        sum = (sum * 10) + root->val; // As given nodes are single digit , simply append the next node's number in sum
        if (!root->left && !root->right)
            return sum;                                          // if the node is leaf node return sum
        return solve(root->left, sum) + solve(root->right, sum); // return sum for left and right
    }
    int sumNumbers(TreeNode *root)
    {
        return solve(root, 0);
    }
};