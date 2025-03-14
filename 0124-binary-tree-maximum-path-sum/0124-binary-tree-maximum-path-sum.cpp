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
    int solve(TreeNode* root, int& max_path_sum){
        if(root == NULL){
            return 0;
        }
        int x = solve(root->left, max_path_sum);
        int y = solve(root->right, max_path_sum);
        int cur_sum = x + y + root->val;
        max_path_sum = max(max_path_sum, cur_sum);
        int best_path = max(x + root->val, y + root->val);
        return best_path > 0 ? best_path : 0;
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        solve(root, ans);
        return ans;
    }
};