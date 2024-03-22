## 637. Average of Levels in Binary Tree

```cpp
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        queue<TreeNode*>q;

        q.push(root);
        while(!q.empty())
        {
            int n= q.size();
            TreeNode* temp;
            double sum =0;

            for(int i=0; i<n; i++)
            {
                temp = q.front(); q.pop();
                sum+= temp->val;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            double avg = sum /n;
            ans.push_back(avg);
        }
        return ans;
    }
};
```
