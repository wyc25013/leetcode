#include <vector>
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
    	int len = nums.size();
    	if(!len) return NULL;

    	int head = 0;
    	int tail = len-1;
    	int mid = (head+tail)/2;
    	TreeNode* root = new TreeNode(nums[mid]);
    	root->left = helper(nums,0,mid-1);
    	root->right = helper(nums,mid+1,len-1);

    	return root;
    }

    TreeNode* helper(vector<int>& nums,int start, int end){
    	if(start > end) return NULL;
    	int mid = (start+end)/2;
    	TreeNode* root = new TreeNode(nums[mid]);
    	root->left = helper(nums,start,mid-1);
    	root->right = helper(nums,mid+1,end);
    	return root;
    }
};