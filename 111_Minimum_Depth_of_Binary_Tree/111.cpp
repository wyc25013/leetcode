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
    int minDepth(TreeNode* root) {
		int min = INT_MAX;
		if(!root) return 0;
		helper(root,0,min);
		return min;        
    }

    void helper(TreeNode* node, int depth, int& min){
    	if(!node->left && !node->right){
    		if(depth+1 < min){
    			min = depth+1;
    			return;
    		}
    	}

    	if(node->left) helper(node->left,depth+1,min);
    	if(node->right) helper(node->right,depth+1,min);

    }
};