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
        int preRoot = preStart;
        int sz = preEnd - preStart;
        TreeNode* cur = new TreeNode(preorder[preStart]);
        map<int, int> hash;
        for(int ind = 0; ind < sz; ind++){
            hash[preorder[preStart + ind + 1]]++;
            hash[postorder[postStart + ind]]--;
            if(hash.find(postorder[postStart + ind]) != hash.end() && hash[postorder[postStart + ind]] == 0){
                hash.erase(postorder[postStart + ind]);
            }
            if(hash.find(preorder[preStart + ind + 1]) != hash.end() && hash[preorder[preStart + ind + 1]] == 0){
                hash.erase(preorder[preStart + ind + 1]);
            }
            if(hash.size() == 0 && postorder[postStart + ind] == preorder[preStart + 1]){
                cur->left = solve(preorder, preStart + 1, preStart + ind + 1, postorder, postStart, postStart + ind);
                cur->right = solve(preorder, preStart + ind + 2, preEnd, postorder, postStart + ind + 1, postEnd);
            }
        }
        return cur;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return solve(preorder, 0, preorder.size() - 1, postorder, 0,  postorder.size() - 1);
    }
};