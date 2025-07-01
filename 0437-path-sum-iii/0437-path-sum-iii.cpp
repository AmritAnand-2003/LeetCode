/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, long long sum, int& target, unordered_map<long, int>& hash, int& ans){
        if(root == NULL){
            return;
        }
        long long cur_sum = sum + root->val;
        // cout<<root->val<<" "<<cur_sum<<" "<<sum<<" "<<cur_sum - target<<endl;
        ans += hash[cur_sum - target];
        hash[cur_sum]++;
        // cout<<ans<<endl;
        solve(root->left, cur_sum, target, hash, ans);
        solve(root->right, cur_sum, target, hash, ans);
        hash[cur_sum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long, int> prefix_sum;
        prefix_sum[0]++;
        int ans = 0;
        solve(root, 0, targetSum, prefix_sum, ans);
        return ans;
    }
};