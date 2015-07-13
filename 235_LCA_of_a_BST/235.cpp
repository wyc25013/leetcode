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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int vp = p->val;
        int vq = q->val;
        int vr = root->val;
        if(vp==vr || vq==vr) return root;
        if((vp < vr && vq > vr) ||(vq < vr && vp > vr)) return root;
        if(vp < vr && vq < vr) return lowestCommonAncestor(root->left,p,q);
        return lowestCommonAncestor(root->right,p,q);
    }
};