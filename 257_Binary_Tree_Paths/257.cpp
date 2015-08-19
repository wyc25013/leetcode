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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> retset;
        vector<int> ret;
        if(!root) return retset;
        ret.push_back(root->val);
        helper(root,ret,retset);
        return retset;
    }
    
    void helper(TreeNode* root, vector<int>& ret, vector<string>& retset){
        if(!root->left && !root->right){
            if(!ret.empty()){
                string s;
                for(int i = 0; i < ret.size()-1; i++)
                    s += to_string(ret[i]) + "->";
                s += to_string(ret[ret.size()-1]);
                retset.push_back(s);
            }
            return;
        }
        if(root->left) {
            ret.push_back(root->left->val);
            helper(root->left,ret,retset);
            ret.pop_back();
        }
        if(root->right) {
            ret.push_back(root->right->val);
            helper(root->right,ret,retset);
            ret.pop_back();
        }
    }
};