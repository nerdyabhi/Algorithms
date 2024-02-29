class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if (!root) return true;
        if(root->val%2==0) return false;

        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        int level = 0;
        while (!q.empty()) {
            TreeNode* prev = nullptr;
            while (q.front() != nullptr) {
                TreeNode* temp = q.front();
                q.pop();

                if ((level % 2 == 0 && temp->val % 2 == 0) || (level % 2 == 1 && temp->val % 2 != 0)) return false;
                if (prev && ((level % 2 == 0 && temp->val <= prev->val) || (level % 2 == 1 && temp->val >= prev->val))) return false;

                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);

                prev = temp;
            }
            q.pop();
            if (!q.empty()) q.push(nullptr);
            level++;
        }

        return true;
    }
};
