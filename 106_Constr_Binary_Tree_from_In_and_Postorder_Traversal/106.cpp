#include <iostream>
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		int len = postorder.size();
        if(!len) return NULL;
		int rootval = postorder[len-1];
		TreeNode* root = new TreeNode(rootval);

		int rootidx;
		for(rootidx = 0; inorder[rootidx] != rootval; rootidx++);

		root->left = helper(inorder,0,rootidx-1,postorder,0,rootidx-1);
		root->right = helper(inorder,rootidx+1,len-1,postorder,rootidx,len-2);

		return root;
    }

    TreeNode* helper(vector<int>& inorder,int start1,int end1,vector<int>& postorder,int start2,int end2){
    	if(start1 > end1)
    		return NULL;

    	int rootval = postorder[end2];
		TreeNode* root = new TreeNode(rootval);

		int rootidx;
		for(rootidx = start1; inorder[rootidx] != rootval; rootidx++);

		root->left = helper(inorder,start1,rootidx-1,postorder,start2,rootidx-1+start2-start1);
		root->right = helper(inorder,rootidx+1,end1,postorder,rootidx+end2-end1,end2-1);

    }
};