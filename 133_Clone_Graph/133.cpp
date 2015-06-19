#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    	unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> ifvisit;
        if(!node) return NULL;
    	queue<UndirectedGraphNode*> bfs;
    	queue<UndirectedGraphNode*> fornew;
    	UndirectedGraphNode* ret = new UndirectedGraphNode(node->label);
		bfs.push(node); ifvisit[node] = ret;
		fornew.push(ret);
		while(bfs.size()){
			UndirectedGraphNode* cur = bfs.front();
			UndirectedGraphNode* curnew = fornew.front();
			int neighb = cur->neighbors.size();
			for(int i = 0; i < neighb; i++){
			    if(ifvisit.find(cur->neighbors[i]) == ifvisit.end()){
				    UndirectedGraphNode* tmp = new UndirectedGraphNode(cur->neighbors[i]->label);
			    	fornew.push(tmp); bfs.push(cur->neighbors[i]); 
			    	ifvisit[cur->neighbors[i]] = tmp;
				    curnew->neighbors.push_back(tmp);
			    } else 
				    curnew->neighbors.push_back(ifvisit[cur->neighbors[i]]);
			}	
			bfs.pop(); fornew.pop();
		}      
		return ret;
    }
};