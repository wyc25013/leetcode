#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
    	vector<int> ret;
    	if(!root) return ret;
        vector<TreeNode*> thislevel;
        thislevel.push_back(root);
        helper(thislevel,ret);
        return ret;
    }

    void helper(vector<TreeNode*>& thislevel, vector<int>& ret){
        if(thislevel.empty()) return;
    	ret.push_back(thislevel.back()->val);
    	int len = thislevel.size();
        vector<TreeNode*> nextlevel;
        for(int i = 0; i < len; i++){
        	TreeNode* cur = thislevel[i];
        	if(cur->left) nextlevel.push_back(cur->left);
        	if(cur->right) nextlevel.push_back(cur->right);
        }
        helper(nextlevel,ret);
    }
};