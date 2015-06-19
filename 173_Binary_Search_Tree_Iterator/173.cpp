#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
	queue<int> small;
	void init(TreeNode* node){
		if(node->left) init(node->left);
		small.push(node->val);
		if(node->right) init(node->right);
	}
public:
    BSTIterator(TreeNode *root) {
        if(root) init(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(small.empty()) return false;
        else return true;
    }

    /** @return the next smallest number */
    int next() {
        int ret = small.front();
        small.pop();
        return ret;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */