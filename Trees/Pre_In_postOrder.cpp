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

void Preorder(node *root)
{
    if (!root)
        return;

    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}

void PostOrder(node *root)
{
    if (!root)
        return;

    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
}

void Inorder(node *root)
{
    if (!root)
        return;

    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

int main()
{
    node *head = build_tree();
    cout << "\nPreoder is : " << endl;
    Preorder(head);
    cout << "\nInorder is : " << endl;
    Inorder(head);
    cout << "\nPostorder is : " << endl;
    PostOrder(head);

    return 0;
}