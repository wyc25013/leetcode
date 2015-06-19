#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* trivial recursive solution 
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(!root) return ret;
        helper(root,ret);
        return ret;
    }

    void helper(TreeNode* node, vector<int>& ret){
    	ret.push_back(node->val);
    	if(node->left) helper(node->left,ret);
    	if(node->right) helper(node->right,ret);
    }
};
*/

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(!root) return ret;
        stack<TreeNode*> ts;
        ts.push(root);
        while(!ts.empty()){
        	TreeNode* node = ts.top();
        	ret.push_back(node->val);
        	ts.pop();
        	if(node->right) ts.push(node->right);
        	if(node->left) ts.push(node->left);
        }


        return ret;
    }
};