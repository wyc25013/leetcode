#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
    	int len = 0;
    	ListNode* iter = head;
    	while(iter){
    		len++;
    		iter = iter->next;
    	}
    	if(!len) return NULL;
    	return helper(head,0,len-1);    
    }

    TreeNode* helper(ListNode*& head,int start, int end){
    	if(start > end) return NULL;
    	int mid = start+(end-start)/2;
    	TreeNode* leftNode = helper(head,start,mid-1);
    	TreeNode* root = new TreeNode(head->val);
    	root->left = leftNode;
    	head = head->next;
    	root->right = helper(head,mid+1,end);
    	return root;
    }
};