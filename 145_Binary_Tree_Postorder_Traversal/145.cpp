/* recursive solution
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
		vector<int> ret;
		if(!root) return ret;
		helper(root,ret);
		return ret;        
    }
    void helper(TreeNode* node, vector<int>& ret){
    	if(node->left) helper(node->left,ret);
    	if(node-right) helper(node->right,ret);
    	ret.push_back(node->val);
    }
};
*/

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
		vector<int> ret;
		if(!root) return ret;
		stack<TreeNode*> ts;
		unordered_set<TreeNode*> vi;
		ts.push(root);
		while(!ts.empty()){
			TreeNode* a = ts.top();
			if(vi.find(a) == vi.end()){
				if(a->right) ts.push(a->right);
				if(a->left) ts.push(a->left);
				vi.insert(a);
			}else{
				ret.push_back(a->val);
				ts.pop();
			}
		}


		return ret;        
    }
};