#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
    	unordered_map<RandomListNode*,RandomListNode*> mm;
    	if(!head) return NULL;
    	RandomListNode* nh = new RandomListNode(head->label);
    	RandomListNode* nr = NULL;
    	if(head->random) nr = new RandomListNode(head->random->label);
    	if(nr) mm[head->random] = nr;
    	nh->random = nr; head = head->next; RandomListNode* gow = nh;
    	while(head){
    		if(mm.find(head) == mm.end()){
    			RandomListNode* nw = new RandomListNode(head->label);
    			gow->next = nw; gow = gow->next;
    			if(head->random && mm.find(head->random) != mm.end())
    				nw->random = mm[head->random];
    			else if(head->random && mm.find(head->random) == mm.end()){
    				nw->random = new RandomListNode(head->random->label);
    				mm[head->random] = nw->random;
    			}
    		}else{
    			RandomListNode* od = mm[head];
    			gow->next = od; gow = gow->next;
    			if(head->random && mm.find(head->random) != mm.end())
    				od->random = mm[head->random];
    			else if(head->random && mm.find(head->random) == mm.end()){
    				od->random = new RandomListNode(head->random->label);
    				mm[head->random] = od->random;
    			}
    		}
    		head = head->next;
    	}
    	return nh;
    }
};