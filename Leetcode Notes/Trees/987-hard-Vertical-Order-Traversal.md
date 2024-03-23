## 987. Vertical Order Traversal of a Binary Tree

<h3>

```cpp
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {


        // a hard problem but easy if u understand the working of DS here
        queue<pair<TreeNode* , pair<int , int>>>q; // a queue to store (node , row , col) to check level order traversal
        vector<vector<int>>ans;

        q.push({root , {0 , 0}});// initialise with root node and 0-row and 0-column
        map<int , map<int, multiset<int>>>mp; // map of type int , map of type multiset and integer
        // haven't used set here cause it's unable to store multiple values with it  , hence we used multiset (ez laif)
        /*
            mp<int ,map<int , multiset> { means a data structure like this}
            ------------------------------
            | col -> | row -> {multiset} |
            |--------------------------- |
            |  -2    |  2 {4}            |
            |  -1    |  1 {2}            |
            |--------|-------------------|
            |   0    | 0 {1}             |
            |        | 2 {5 , 6}         |
            |------- |-------------------|
            |       and so and so on     |
            |----------------------------|

            as map stores elements in sorted order :
            it'll store in sorted column order : -2 , -1 , 0 , 1 , 2
            Now for corresponding row it'll also store it in sorted order :


        */
        while(!q.empty())
        {
            auto temp = q.front(); q.pop();
            TreeNode*&node = temp.first;
            auto coordinate = temp.second;
            int &row = coordinate.first;
            int &col = coordinate.second;

            mp[col][row].insert(node->val);


            if(node->left)   q.push({node->left , {row+1 , col -1}});
            if(node->right)   q.push({node->right , {row+1 , col +1}});

        }

        for(auto &it : mp) // just iterate through the map and store the result ez laif
        { // come visit again after studying maps and stuffs for better understanding
            vector<int> res;
            auto &colmp = it.second;
            for(auto &colmpIT : colmp)
            {
                auto &set1 = colmpIT.second;
                res.insert(res.end() ,set1.begin(), set1.end() );

            }
            ans.push_back(res);
        }

        return ans;
    }
};

```
