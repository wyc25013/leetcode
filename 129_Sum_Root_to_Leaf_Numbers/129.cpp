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
    int sumNumbers(TreeNode* root) {
		int ret = 0;
		if(!root) return ret;
		int pathsum = 0;
		helper(root,ret,pathsum);
		return ret;        
    }

    void helper(TreeNode* node, int& ret, int pathsum){
    	if(!node->left && !node->right){
    		pathsum = pathsum*10 + node->val;
    		ret += pathsum;
    		return;
    	}

    	pathsum = pathsum*10 + node->val;
    	if(node->left) helper(node->left, ret, pathsum);
    	if(node->right) helper(node->right, ret, pathsum);
    }
};