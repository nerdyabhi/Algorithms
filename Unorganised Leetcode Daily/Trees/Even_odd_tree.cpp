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
    bool isEvenOddTree(TreeNode *root)
    {

        queue<TreeNode *> q;

        if (root->val % 2 == 0)
            return false;

        q.push(root);
        q.push(NULL);
        int i = 0;
        while (!q.empty())
        {

            if (q.front() == NULL)
            {
                i++;
                q.pop();
                if (!q.empty())
                    q.push(NULL);
            }

            else
            {
                TreeNode *temp = q.front();
                q.pop();

                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);

                if (i % 2 == 0)
                {
                    if (temp->val % 2 == 0)
                        return false;
                    if (q.front())
                    {
                        if (q.front()->val % 2 == 0)
                            return false;
                        if (temp->val >= q.front()->val)
                            return false;
                        if (temp->val >= q.front()->val)
                            return false;
                    }
                }

                else
                {
                    if (temp->val % 2 != 0)
                        return false;
                    if (q.front())
                    {
                        if (q.front()->val % 2 != 0)
                            return false;
                        if (temp->val <= q.front()->val)
                            return false;
                        if (temp->val <= q.front()->val)
                            return false;
                    }
                }
            }
        }

        return true;
    }
};