## [BST TO MAX -HEAP ](https://www.geeksforgeeks.org/problems/bst-to-max-heap/1)

---

```cpp

 void find_inorder(Node* &root , vector<int> & arr)
    {
        if(!root) return;

        find_inorder(root->left , arr);

        arr.push_back(root->data);

        find_inorder(root->right , arr);

    }


    void solve(Node* &root ,vector<int> &arr , int &index)
    {
        if(!root) return;
        if(index >= arr.size()) return;

        solve(root->left , arr , index);
        solve(root->right , arr , index);
        root->data = arr[index++];

    }

    void convertToMaxHeapUtil(Node* root)
    {
        // Your code goes here
        vector<int>inorder;
        find_inorder(root , inorder);
        int index =0;
        solve(root , inorder , index);

    }
```
