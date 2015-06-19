#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//d&c solution
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {        
    	if(lists.empty()) return NULL;
		while(lists.size() != 1){
			for(int i = 0; i < lists.size()-1;i++){
				lists[i] = helper(lists[i],lists[i+1]);
				if(i+1 < lists.size())
					lists.erase(lists.begin()+i+1);
			}
		}
		return lists[0];
    }
    ListNode* helper(ListNode* a, ListNode* b){
    	ListNode dummy(-1);
    	ListNode* head = &dummy;
    	ListNode* ha = a; ListNode* hb = b;
    	while(ha && hb){
    		if(ha->val < hb->val){
    			head->next = ha; head = head->next;
    			ha = ha->next; head->next = NULL;
    		} else {
    			head->next = hb; head = head->next;
    			hb = hb->next; head->next = NULL;
    		}
    	}
    	if(ha && !hb) head->next = ha;
    	else if(hb && !ha) head->next = hb;
    	return dummy.next;
    }
};

int main(){
	vector<ListNode*> a;
	for(int i = 0; i < 10000; i++)
		a.push_back(new ListNode(i));
//	a.push_back(b);
	Solution soln;
	ListNode* c = soln.mergeKLists(a);
	while(c){
		cout<<c->val<<" ";
		c = c->next;
	} 
	cout<<endl;
}