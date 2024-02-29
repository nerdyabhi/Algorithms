class Solution
{
public:
    int findBottomLeftValue(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);

        int ans = root->val;
        while (!q.empty())
        {
            TreeNode *temp = q.front();
            ans = temp->val;
            q.pop();

            if (temp->right)
                q.push(temp->right);
            if (temp->left)
                q.push(temp->left);
        }

        return ans;
    }
};