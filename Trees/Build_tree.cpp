#include <iostream>
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

void Level_Traversal()
{
    
}

int main()
{
    node* head = build_tree();
    return 0;
}