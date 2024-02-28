#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    node *left;
    node *right;
    int data;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node *build_tree()
{
    int data;
    cin >> data;

    if (data == -1)
        return NULL;
    node *root = new node(data);

    cout << "Enter data for left part of " << data << endl;
    root->left = build_tree();
    cout << "Enter data for right part of " << data << endl;
    root->right = build_tree();

    return root;
}

void Level_Traversal(node *root)
{
    queue<node *> q;

    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (!temp)
        {
            if (!q.empty())
                q.push(NULL);
            cout << endl;
        }

        else
        {
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

int main()
{
    node *head = build_tree();
    Level_Traversal(head);
    return 0;
}