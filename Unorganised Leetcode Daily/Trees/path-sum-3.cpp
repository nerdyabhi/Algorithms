class Solution {
public:

    void solve(TreeNode* root , long long targetSum , unordered_map<long long , long long>&mp , int &ans , long long sum)
    {
        if(!root) return;
        sum = sum + root->val;
        int temp = sum - targetSum;

       int count = mp[temp];
       ans+= mp[temp];
        mp[sum]++;

         solve(root->left , targetSum , mp , ans  , sum);
         solve(root->right , targetSum , mp , ans , sum);

        mp[sum]--;



        return;
    }

    int pathSum(TreeNode* root, int targetSum) {
    unordered_map<long long, long long> mp;
    int ans = 0;
    long long sum = 0;
    if (root) {
        mp[0] = 1;
        solve(root, targetSum, mp, ans, sum);
    }
    return ans;
}