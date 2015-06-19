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
    void flatten(TreeNode* root) {
    	if(!root) return;
    	root = helper(root);
    }

    TreeNode* helper(TreeNode* node){
    	if(!node) return NULL;
    	TreeNode* leftnode = helper(node->left);
		TreeNode* rightnode = helper(node->right); 
		node->left = NULL; 
		if(leftnode){ 
			node->right = leftnode;
			leftnode->left = NULL;
			while(leftnode->right)
				leftnode = leftnode->right;
			leftnode->right = rightnode;
		}
		else{
			node->right = rightnode;
		}
		return node;
    }
};