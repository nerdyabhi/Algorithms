int height(TreeNode *root)
{
    if (!root)
        return 0;

    return 1 + max(height(root->left), height(root->right));
}
bool isBalanced(TreeNode *root)
{
    if (!root)
        return true;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if (abs(leftHeight - rightHeight) > 1)
        return false;

    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);

    return left && right;
}