#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* not good
 *
class Solution {
public:
    bool isValidBST(TreeNode* root) {
    	if(!root)
    		return true;
		stack<TreeNode*> left;
		stack<TreeNode*> right;
		int pval = root->val;
		if(root->left) left.push(root->left);
		if(root->right) right.push(root->right);

		while(left.size()){
			TreeNode* cur = left.top();
			if(cur->val >= pval)
				return false;
			left.pop();
			if(cur->left) left.push(cur->left);
			if(cur->right) left.push(cur->right);
		}

		while(right.size()){
			TreeNode* cur = right.top();
			if(cur->val <= pval)
				return false;
			right.pop();
			if(cur->left) right.push(cur->left);
			if(cur->right) right.push(cur->right);
		}

		return (isValidBST(root->left) && isValidBST(root->right));
    }
};
*/

class Solution {
public:
    bool isValidBST(TreeNode* root) {
    	if(!root) return true;
		return isValid(root,LLONG_MIN,LLONG_MAX);
    }
    bool isValid(TreeNode* node, long long min, long long max){
    	if(!node) return true;
    	if(node->val >= max || node->val <= min) return false;
    	if(!isValid(node->left,min,node->val) || !isValid(node->right,node->val,max)) return false;
    	return true;
    }
};
