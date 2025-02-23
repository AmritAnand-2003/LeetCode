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
    TreeNode* solve(vector<int>& preorder, int preStart, int preEnd, vector<int>& postorder, int postStart, int postEnd){
        if(preEnd < preStart || postEnd < postStart){
            return NULL;
        }
        int sz = preEnd - preStart;
        TreeNode* cur = new TreeNode(preorder[preStart]);
        for(int ind = 0; ind < sz; ind++){
            if(postorder[postStart + ind] == preorder[preStart + 1]){
                cur->left = solve(preorder, preStart + 1, preStart + ind + 1, postorder, postStart, postStart + ind);
                cur->right = solve(preorder, preStart + ind + 2, preEnd, postorder, postStart + ind + 1, postEnd);
                break;
            }
        }
        return cur;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return solve(preorder, 0, preorder.size() - 1, postorder, 0,  postorder.size() - 1);
    }
};