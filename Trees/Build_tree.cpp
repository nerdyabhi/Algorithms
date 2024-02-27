#include <iostream>
using namespace std;

class node
{
    node* left;
    node* right;
    int data;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

int main()
{
    node* abhi;
    abhi = new node(56);
    return 0;
}