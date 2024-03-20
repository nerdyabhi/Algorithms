### 199. Binary tree right side view

```cpp
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        //last node on level order traversal is our answer #ez
        if(!root) return {};
        queue<TreeNode*>q;
        vector<int> ans;
        q.push(root);

        while(!q.empty())
        {
            int n = q.size();
            TreeNode* temp = NULL;

            while(n--)
            {
                // computes one level
                temp = q.front(); q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }

            ans.push_back(temp->val); // last element is placed in array (ez laif)
        }

        return ans;
    }
};
```
