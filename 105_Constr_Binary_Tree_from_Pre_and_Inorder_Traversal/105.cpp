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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    	if(!preorder.size())
    		return NULL;
		int rootval = preorder[0];
		TreeNode* root = new TreeNode(rootval);
		int len = preorder.size();

		int rootidx;
		for(rootidx = 0; inorder[rootidx] != rootval; rootidx++);

		root->left = helper(preorder,1,rootidx,inorder,0,rootidx-1);
		root->right = helper(preorder,rootidx+1,len-1,inorder,rootidx+1,len-1);

		return root;
    }

    TreeNode* helper(vector<int>& preorder,int start1,int end1,vector<int>& inorder,int start2,int end2){
    	if(start1 > end1)
    		return NULL;
    	int rootval = preorder[start1];
		TreeNode* root = new TreeNode(rootval);

		int rootidx;
		for(rootidx = start2; inorder[rootidx] != rootval; rootidx++);

		root->left = helper(preorder,start1+1,rootidx+start1-start2,inorder,start2,rootidx-1);
		root->right = helper(preorder,rootidx+1+end1-end2,end1,inorder,rootidx+1,end2);

    }
};