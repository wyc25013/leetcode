#include <vector>
#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

struct TreeNode {
  	int val;
  	TreeNode *left;
  	TreeNode *right;
  	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* recursive solution
 *
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
    	vector<int> ret;
    	if(root == NULL)
    		return ret;
      helper(root,ret);
      return ret;
    }

    void helper(TreeNode* cur, vector<int>& ret){
    	if(cur->left != NULL){
    		helper(cur->left,ret);
    		ret.push_back(cur->val);
    		if(cur->right != NULL)
    			helper(cur->right,ret);
    		else
    			return;
    	} else {
    		ret.push_back(cur->val);
    //		helper(cur->right,ret);
    		if(cur->right != NULL)
    			helper(cur->right,ret);
    		else
    			return;
    	}
    }
};
*/

//iterative solution with hash
//stack is important
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
    	vector<int> ret;
    	if(root == NULL)
    		return ret;
       	unordered_map<TreeNode*,bool> if_visit;
       	stack<TreeNode*> to_visit;
       	to_visit.push(root);
       	if_visit.insert(pair<TreeNode*,bool>(root,false));
       	while(to_visit.size()){
       		TreeNode* tmp = to_visit.top();
       		if(tmp->left){
       			if(if_visit.find(tmp->left) == if_visit.end()){
       				if_visit.insert(pair<TreeNode*,bool>(tmp->left,false));
       				to_visit.push(tmp->left);
       			}
       			else{
       				if(!if_visit[tmp->left])
       					to_visit.push(tmp->left);
       				else{
       					ret.push_back(tmp->val);
       					if_visit[tmp] = true;
       					to_visit.pop();
       					if(tmp->right){
		       				to_visit.push(tmp->right);
		       				if_visit.insert(pair<TreeNode*,bool>(tmp->right,false));
		       			}
       				}
       			}
       		}else{
       			ret.push_back(tmp->val);
       			if_visit[tmp] = true;
       			to_visit.pop();
       			if(tmp->right){
       				to_visit.push(tmp->right);
       				if_visit.insert(pair<TreeNode*,bool>(tmp->right,false));
       			}
       		}
       	}
       	return ret;
    }
};

/*iterative solution without hash
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> nodes;
    stack<TreeNode*> toVisit;
    TreeNode* curNode = root;
    while (curNode || !toVisit.empty()) {
        if (curNode) {
            toVisit.push(curNode);
            curNode = curNode -> left;
        }
        else {
            curNode = toVisit.top();
            toVisit.pop();
            nodes.push_back(curNode -> val);
            curNode = curNode -> right;
        }
    }
    return nodes;
}
*/

int main(){
	TreeNode one(1);
	TreeNode two(2);
	TreeNode three(3);
//	TreeNode four(4);
//	TreeNode five(5);

	one.left = &two;
	two.left = &three;
//	three.left = &four;
//	four.right = &five;

	Solution soln;
	vector<int> a = soln.inorderTraversal(&one);
	int i = 0;
	while(i < a.size()){
		cout<<a[i]<<" ";
		i++;
	}
	cout<<endl;
}