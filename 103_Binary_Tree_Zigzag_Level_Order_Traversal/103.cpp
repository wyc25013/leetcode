#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int> > ret;
		if(!root) return ret;
		queue<TreeNode*> bfs;
		bfs.push(root);
		bool dir = true;
		while(bfs.size()){
			stack<TreeNode*> nextLevel;
			vector<int> thisLevel;
			while(bfs.size()){
				TreeNode* f = bfs.front();
				bfs.pop();
				if(dir){
					if(f->left) nextLevel.push(f->left);
					if(f->right) nextLevel.push(f->right);
				}else{
					if(f->right) nextLevel.push(f->right);
					if(f->left) nextLevel.push(f->left);
				}
				thisLevel.push_back(f->val);
			}
			dir = !dir;
			ret.push_back(thisLevel);
			while(nextLevel.size()){
				bfs.push(nextLevel.top());
				nextLevel.pop();
			}
		}        
		return ret;        
    }
};