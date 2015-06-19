#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
    	vector<vector<int> > retset;
        if(!root) return retset;

        vector<int> ret;
		int csum = 0;
		helper(root,root->val,csum,sum,ret,retset);        
		return retset;
    }

    void helper(TreeNode* node,int val, int cursum, int sum, vector<int>& ret, vector<vector<int> >& retset){
    	if(!node->left && !node->right){
    		if(val+cursum == sum){
    			ret.push_back(val);
    			retset.push_back(ret);
    			ret.pop_back();
    		}
    		return;
    	}

    	ret.push_back(val);
    	if(node->left) helper(node->left,node->left->val,cursum+val,sum,ret,retset);
//    	ret.pop_back();
//    	ret.push_back(val);
    	if(node->right) helper(node->right,node->right->val,cursum+val,sum,ret,retset);
    	ret.pop_back();
    }
};