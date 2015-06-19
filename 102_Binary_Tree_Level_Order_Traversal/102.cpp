#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int> > ret;
		if(!root) return ret;
		queue<TreeNode*> bfs;
		bfs.push(root);
		while(bfs.size()){
			queue<TreeNode*> nextLevel;
			vector<int> thisLevel;
			while(bfs.size()){
				TreeNode* f = bfs.front();
				bfs.pop();
				if(f->left) nextLevel.push(f->left);
				if(f->right) nextLevel.push(f->right);
				thisLevel.push_back(f->val);
			}
			ret.push_back(thisLevel);
			while(nextLevel.size()){
				bfs.push(nextLevel.front());
				nextLevel.pop();
			}
		}        
		return ret;
    }
};