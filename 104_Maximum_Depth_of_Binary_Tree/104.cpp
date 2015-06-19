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
    int maxDepth(TreeNode* root) {
		if(!root) return 0;
		int max = 0;   

		helper(root,0,max);
		return max;     
    }

    void helper(TreeNode* root, int depth, int& max){
    	if(!root->left && !root->right){
    		if(depth+1 > max)
    			max = depth+1;
    		return;
    	}

    	if(root->left)
    		helper(root->left, depth+1,max);
    	if(root->right)
    		helper(root->right,depth+1,max);
    }
};