#### Code Snippet for Leetcode 105

```cpp
class Solution {
public:

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder , int s , int e  , int& index)
    {
        if(s >e) return nullptr;
         int root_val = preorder[index++];
        int i=s;
        for(i =s; i<e; i++)
        {
            if(inorder[i] == root_val) break;
        }
         TreeNode* root = new TreeNode(root_val);

         root->left = solve(preorder , inorder , s , i-1 , index);
         root->right = solve(preorder , inorder , i+1, e, index);

         return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int index = 0; //initialise an index to travel preorder
        int n= preorder.size(); // calculate the no. of nodes

        return solve(preorder , inorder , 0 , n-1 , index); // call helper function


    }
};
```

#### Dry Run on Test Case [3, 9, 20, 15, 7]

#### Preorder Traversal: [3, 9, 20, 15, 7]

#### Inorder Traversal: [9, 3, 15, 20, 7]

We start with the root node value from the preorder traversal:

- **Root Node**: Value is 3.
- **Find Root in Inorder**: In the inorder traversal, 3 is found at index 1.
- **Construct Root Node**: Create a TreeNode with value 3.

Now, we recursively construct the left and right subtrees:

#### Left Subtree:

- **Preorder Traversal**: [9]
- **Inorder Traversal**: [9]
- Since both preorder and inorder traversals have only one element, the left subtree has only one node, which is 9.

#### Right Subtree:

- **Preorder Traversal**: [20, 15, 7]
- **Inorder Traversal**: [15, 20, 7]

- **Root Node**: Value is 20.
- **Find Root in Inorder**: In the inorder traversal, 20 is found at index 1.
- **Construct Root Node**: Create a TreeNode with value 20.

##### Left Subtree of Right Subtree:

- **Preorder Traversal**: [15]
- **Inorder Traversal**: [15]
- Since both preorder and inorder traversals have only one element, the left subtree has only one node, which is 15.

##### Right Subtree of Right Subtree:

- **Preorder Traversal**: [7]
- **Inorder Traversal**: [7]
- Since both preorder and inorder traversals have only one element, the right subtree has only one node, which is 7.

### Constructed Binary Tree:

```
  3
 / \
9   20
   /  \
  15   7
```
