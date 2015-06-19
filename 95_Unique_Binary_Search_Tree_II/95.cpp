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
    vector<TreeNode*> generateTrees(int n) {
    	vector<vector<TreeNode*> > treemap;
    	TreeNode* one = new TreeNode(1);
    	vector<TreeNode*> ones;
    	ones.push_back(one);
    	if(n==1)
    		return ones;
    	vector<TreeNode*> zeros;
    	zeros.push_back(NULL);
    	treemap.push_back(zeros);
    	treemap.push_back(ones);

    	for(int i = 2; i <=n; i++){
    		vector<TreeNode*> ret;
    		for(int j = 0; j < i; j++){	// j = # left children
    			vector<TreeNode*> leftChild = treemap[j];
    			vector<TreeNode*> rightChild = shifts(j+1,treemap[i-1-j]);
    			int len_left = leftChild.size();
    			int len_right = rightChild.size();
    			for(int p = 0; p < len_left; p++){
    				for(int q = 0; q < len_right; q++){
    					TreeNode* root = new TreeNode(j+1);
    					root->left = leftChild[p];
    					root->right = rightChild[q];
    					ret.push_back(root);
    				}
    			}	
    		}
    		treemap.push_back(ret);
    	}
		return treemap[n];
    }

    vector<TreeNode*> shifts(int add,vector<TreeNode*>& origin){
    	if(origin[0] == NULL)
    		return origin;
    	int len = origin.size();
    	vector<TreeNode*> ret;
    	for(int i = 0; i < len; i++){
       		TreeNode* newTree = traversal(origin[i],add);
       		ret.push_back(newTree);
       	}
       	return ret;
    }

    TreeNode* traversal(TreeNode* root,int add){
    	if(!root) 
    		return root;
    	TreeNode* leftChild = traversal(root->left,add);q
    	TreeNode* newNode = new TreeNode(root->val+add);
    	TreeNode* rightChild = traversal(root->right,add);
    	newNode->left = leftChild;
    	newNode->right = rightChild;
    	return newNode;
    }
};

int main(){
	Solution soln;
	vector<TreeNode*> a = soln.generateTrees(3);
	cout<<a[0]->val<<" "<<a[0]->left<<" "<<a[0]->right<<endl;
	cout<<a[1]->val<<" "<<a[1]->left<<" "<<a[1]->right<<endl;
	cout<<a[2]->val<<" "<<a[2]->left<<" "<<a[2]->right<<endl;
	cout<<a[3]->val<<" "<<a[3]->left<<" "<<a[3]->right<<endl;
	cout<<a[4]->val<<" "<<a[4]->left<<" "<<a[4]->right<<endl;
}