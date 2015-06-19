#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
		if(!head) return NULL;
		ListNode* helper = head;
		while(helper && helper->next){
			if(helper->next->val < helper->val){
				ListNode* redis = helper->next;
				helper->next = helper->next->next;
				ListNode* here = head;
				ListNode* prehere = head;
				while(redis->val > here->val){
					if(here != prehere){
						here = here->next;
						prehere = prehere->next;
					}else
						here = here->next;
				}

				if(here == prehere){
					redis->next = head;
					head = redis;
				} else {
					prehere->next = redis;
					redis->next = here;	
				}
			} else
				helper = helper->next;
		}  
		return head;    
    }
};

int main(){
	ListNode a1(0);
	ListNode a2(4);
	ListNode a3(3);
	ListNode a4(2);
	ListNode a5(1);
	a1.next = &a2;
	a2.next = &a3;
	a3.next = &a4;
	a4.next = &a5;
	Solution soln;
	ListNode* a = soln.insertionSortList(&a1);
	while(a){
		cout<<a->val<<" ";
		a = a->next;
	}
	cout<<endl;
}