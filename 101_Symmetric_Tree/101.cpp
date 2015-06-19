#include <iostream>
#include <deque>
using namespace std;

struct TreeNode {
   int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/* iterative solution
 *
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        deque<TreeNode*> d;
        if(!root) return true;
        d.push_back(root);
        if(root->left && root->right){
        	d.push_front(root->left);
        	d.push_back(root->right);
        }else{
        	if(root->left || root->right)
        		return false;
        	else
        		return true;
        }

        while(d.size() != 1){
        	TreeNode* head = d.front();
        	TreeNode* tail = d.back();
        	if(head->val != tail->val)
        		return false;
        	d.pop_front(); d.pop_back();

        	if(head->left && tail->right){
        		d.push_front(head->left);
	        	d.push_back(tail->right);
	        }else{
	        	if(head->left || tail->right)
	        		return false;
	        }

	        if(head->right && tail->left){
        		d.push_front(head->right);
	        	d.push_back(tail->left);
	        }else{
	        	if(head->right || tail->left)
	        		return false;
	        }
        }

        return true;
    }
};
*/

//recursive solution
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return isImageRecursive(root->left,root->right);
    }

    bool isImageRecursive(TreeNode* a, TreeNode* b){//recursively
        if((!a)&&(!b)) return true;
        if(!(a&&b)) return false;
        return ((a->val==b->val)&&(isImageRecursive(a->left,b->right))&&(isImageRecursive(a->right,b->left)));
    }
};
