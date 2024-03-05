vector<int> topView(Node *root)
{
    // Your code here
    if (!root)
        return {};

    queue<pair<Node *, int>> q;
    map<int, int> mp;
    vector<int> ans;

    q.push({root, 0});

    while (!q.empty())
    {
        Node *temp = q.front().first;
        int col = q.front().second;
        q.pop();

        if (mp.find(col) == mp.end())
            mp[col] = temp->data;

        if (temp->left)
            q.push({temp->left, col - 1});

        if (temp->right)
            q.push({temp->right, col + 1});
    }

    for (auto it : mp)
        ans.push_back(it.second);
    return ans;
}