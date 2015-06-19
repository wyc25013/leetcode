#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
		stack<TreeNode*> ps;
		stack<TreeNode*> qs;
		if(!p && !q) return true;
		else if((!p&&q) || (!q&&p)) return false;
		ps.push(p);
		qs.push(q);
		while(ps.size()){
			if(qs.size() != ps.size())
				return false;
			TreeNode* pt = ps.top();
			TreeNode* qt = qs.top();
			if(pt->val != qt->val)
				return false;
			ps.pop(); qs.pop();
			if(pt->left && qt->left){
				ps.push(pt->left);
				qs.push(qt->left);
			}else{
				if(pt->left || qt->left)
					return false;
			}

			if(pt->right && qt->right){
				ps.push(pt->right);
				qs.push(qt->right);
			}else{
				if(pt->right || qt->right)
					return false;
			}
			
		}
		return true;
    }
};