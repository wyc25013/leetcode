/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int ret;
        helper(root,count,ret,k);
        return ret;
    }
    
    void helper(TreeNode* node, int& count, int& ret,int k){
        if(count==k) return;
        if(!node) return;
        helper(node->left,count,ret,k);
        count++;
        if(count==k){
            ret = node->val;
            return;
        }
        helper(node->right,count,ret,k);
    }
};