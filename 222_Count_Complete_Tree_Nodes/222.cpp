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
    int countNodes(TreeNode* root) {
    	if(!root) return 0;
    	TreeNode* cur = root;
    	int lh = leftheight(cur);
    	int rh = rightheight(cur);
    	int ret = pow(2,rh)-1;
    	if(lh == rh) return ret;
		helper(root->left,ret,true);
		helper(root->right,ret,false);
		return ret;
    }

    void helper(TreeNode* node, int& ret, bool flag){
    	if(!node) return;
    	int lh = leftheight(node);
    	int rh = rightheight(node);
    	
    	if(lh == rh){
    		if(flag)
    			ret += pow(2,rh-1);
    	} else {
			helper(node->left,ret,true);
			helper(node->right,ret,false);
		}
    }

    int leftheight(TreeNode* node){
    	int ret = 1;
    	while(node->left){
    		ret++;
    		node = node->left;
    	}
    	return ret;
    }

    int rightheight(TreeNode* node){
    	int ret = 1;
    	while(node->right){
    		ret++;
    		node = node->right;
    	}
    	return ret;
    }
};