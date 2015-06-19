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
    	if(!root->left) return;
    	TreeLinkNode* head = root;
    	TreeLinkNode* nextnode = root->next;
    	TreeLinkNode* leftnode = root->left;
    	TreeLinkNode* rightnode = root->right;

    	leftnode->next = rightnode;
    	while(nextnode){
    		rightnode->next = nextnode->left;
    		nextnode->left->next = nextnode->right;
    		leftnode = nextnode->left;
    		rightnode = nextnode->right;
    		nextnode = nextnode->next;
    	}
    	connect(head->left);
    }
};