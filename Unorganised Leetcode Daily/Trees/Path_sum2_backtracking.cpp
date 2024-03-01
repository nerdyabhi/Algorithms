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
class Solution
{
public:
    void solve(TreeNode *&root, int &sum, int &targetSum, vector<vector<int>> &ans, vector<int> &path)
    {
        if (!root)
            return;

        path.push_back(root->val);
        sum += root->val;
        if (!root->left && !root->right)
        {
            if (sum == targetSum)
                ans.push_back(path);
            path.pop_back();
            sum -= root->val;
            return;
        }

        solve(root->left, sum, targetSum, ans, path);
        solve(root->right, sum, targetSum, ans, path);

        // back-track
        path.pop_back();
        sum -= root->val;
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> ans;
        vector<int> path;
        int sum = 0;

        solve(root, sum, targetSum, ans, path);
        return ans;
    }
};