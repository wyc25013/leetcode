#include <iostream>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
    	if(!root) return true;
    	return isBalanced(root->left) && isBalanced(root->right) && abs(depth(root->left)-depth(root->right)) <= 1;
    }

    int depth(TreeNode* node){
    	if(!node) return 0;
    	return max(depth(node->left),depth(node->right))+1;
    }
};