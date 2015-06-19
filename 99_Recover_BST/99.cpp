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
    void recoverTree(TreeNode* root) {
    	if(!root) return;
    	TreeNode* cl = checkchild(root->val,root->left,-1);
    	TreeNode* cr = checkchild(root->val,root->right,1);
    	if(!cl && !cr){
    		recoverTree(root->left);
    		recoverTree(root->right);
    	} else if(!cl && cr)
    		swapval(cr,root);
    	else if(cl && !cr)
    		swapval(cl,root);
    	else	// cl && cr
    		swapval(cl,cr);
    	return;
    }

    void swapval(TreeNode* a, TreeNode* b){
    	int tmp = a->val;
    	a->val = b->val;
    	b->val = tmp;
    }

    TreeNode* checkchild(int pval, TreeNode* node, int flag){
    	if(!node) return NULL;
    	if(flag==1){	// right child
    		int min = pval; TreeNode* ret = NULL;
    		if(node->val < pval){
    			min = node->val;
    			ret = node;		
    		}
    		TreeNode* cl = checkchild(min,node->left,1);
    		TreeNode* cr = checkchild(min,node->right,1);
    		if(cl){
    			ret = cl; min = cl->val;
    		}
    		if(cr && cr->val < min){
    			ret = cr; min = cr->val;
    		}
    		return ret;
    	}else{		//flag==-1 left child
    		int max = pval; TreeNode* ret = NULL;
    		if(node->val > pval){	
    			max = node->val;
    			ret = node;
    		}
    		TreeNode* cl = checkchild(max,node->left,-1);
    		TreeNode* cr = checkchild(max,node->right,-1);
    		if(cl){
    			ret = cl; max = cl->val;
    		}
    		if(cr && cr->val > max){
    			ret = cr; max = cr->val;
    		}
    		return ret;
    	}
    }
};