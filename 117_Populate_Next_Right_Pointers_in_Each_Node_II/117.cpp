#include <iostream>
using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
    	if(!root) return;
    	
    	TreeLinkNode* head = root;
    	TreeLinkNode* nexthead;
    	TreeLinkNode* tmp;
    	
    	//find next level's head
    	while(head && !head->left && !head->right)
    		head = head->next;
    	if(!head) return;
    	else{
    		if(head->left){
    			nexthead = head->left;
    			if(head->right){
    				nexthead->next = head->right;
    				tmp = head->right;
    			}else
    				tmp = head->left; 
    		} else {
    			nexthead = head->right;
    			tmp = head->right;
    		}
    	}

    	//link next level
    	TreeLinkNode* nextnode = head->next;
    	while(nextnode){
    		while(nextnode && !nextnode->left && !nextnode->right)
    			nextnode = nextnode->next;
    		if(!nextnode) break;
    		else{
    			if(nextnode->left){
	    			if(nextnode->right){
	    				tmp->next = nextnode->left;
	    				nextnode->left->next = nextnode->right;
	    				tmp = nextnode->right;
	    			}else{
	    				tmp->next = nextnode->left;
	    				tmp = nextnode->left;
	    			}
    			} else {
	    			tmp->next = nextnode->right;
	    			tmp = nextnode->right;
	    		}
	    	}
	    	nextnode = nextnode->next;
    	}
    	connect(nexthead);    
    }
};