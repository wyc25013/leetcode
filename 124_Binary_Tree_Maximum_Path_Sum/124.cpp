#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	unordered_map<TreeNode*,int> mps;
public:
    int maxPathSum(TreeNode* root) {
		if(!root) return INT_MIN;
		int sum = root->val+max(0,dfs(root->left))+max(0,dfs(root->right));
		return max(sum, max(maxPathSum(root->left),maxPathSum(root->right)));
    }

    int dfs(TreeNode* node){
    	if(!node) return INT_MIN;
    	if(mps.find(node) != mps.end()) return mps[node];
    	int ret = node->val+max(0,max(dfs(node->left),dfs(node->right)));
    	mps[node] = ret; return ret;
    }

    /* better solution 
     * traverse the tree only once
    int maxPathSum(TreeNode* root) {
		int ret = INT_MIN;
		dfs(root,ret);
		return ret;
    }

    int dfs(TreeNode* node, int& ret){
    	if(!node) return 0;
    	int lret = max(0,dfs(node->left,ret));
    	int rret = max(0,dfs(node->right,ret));
    	ret = max(ret, node->val+lret+rret);
    	return max(node->val+lret,node->val+rret);
    }
    */
};