#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
		if(!root) return false;
		int csum = 0;
		bool ret = false;
		helper(root,root->val,csum,sum,ret);        
		return ret;
    }

    void helper(TreeNode* node,int val, int cursum, int sum, bool& ret){
    	if(!node->left && !node->right){
    		if(val+cursum == sum)
    			ret = true;
    		return;
    	}

    	if(node->left) helper(node->left,node->left->val,cursum+val,sum,ret);
    	if(node->right) helper(node->right,node->right->val,cursum+val,sum,ret);
    }
};