#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// O(NlogN) time and O(1) space ==> mergesort or quicksort
/* mergesort
class Solution {
public:
    ListNode* sortList(ListNode* head) {
    	if(!head) return NULL;
    	ListNode dummy(-1);
    	ListNode* dhead = &dummy; dhead->next = head;
    	ListNode* walker = dhead;	// walker and runner are to find
    	ListNode* runner = dhead;	// the middle between start and end
    	while(runner != NULL && runner->next != NULL){
    		walker = walker->next;
    		runner = runner->next->next;
    	}

    	if(walker->next == NULL){
    		return head;
    	} else {
    		ListNode* newstart = walker->next;
    		walker->next = NULL;	//breaking chain here is important for merge part
    		ListNode* sortedfirst = sortList(head);
    		ListNode* sortedsecond = sortList(newstart);
    		return merge(sortedfirst,sortedsecond);
    	}
    }

    ListNode* merge(ListNode* a, ListNode* b){
    	ListNode dummy(-1);
    	ListNode* cur = &dummy;
    	while(a && b){
    		if(a->val < b->val){
    			cur->next = a;
    			cur = cur->next;
    			a = a->next;
    		} else {
    			cur->next = b;
    			cur = cur->next;
    			b = b->next;
    		}
    	}
    	if(a) cur->next = a;
    	if(b) cur->next = b;
    	return dummy.next;
    }
};
*/

// quicksort
class Solution {
public:
    ListNode* sortList(ListNode* head) {
		if(!head) return NULL;
		//choose mid as pivot
    	ListNode dummy(-1);
    	ListNode* dhead = &dummy; dhead->next = head;
    	ListNode* walker = dhead;	// walker and runner are to find
    	ListNode* runner = dhead;	// the middle between start and end
    	while(runner != NULL && runner->next != NULL){
    		walker = walker->next;
    		runner = runner->next->next;
    	}    

    	if(walker->next == NULL){
    		return head;
    	} else {
    		//partition
    		ListNode* pivot = walker;
    		ListNode* trvsl = head;
    		ListNode d1(-1); ListNode d2(-2);
    		ListNode* former = &d1; ListNode* latter = &d2;
    		while(trvsl){
    			if(trvsl != pivot){
    				if(trvsl->val < pivot->val){
    					former->next = trvsl;
    					former = former->next;
    					trvsl = trvsl->next;
    					former->next = NULL;
    				} else {
    					latter->next = trvsl;
    					latter = latter->next;
    					trvsl = trvsl->next;
    					latter->next = NULL;    					
    				}
    			}else trvsl = trvsl->next;
    		}
    		ListNode* sp = pivot;
    		ListNode* sh = d2.next;
    		while(sh && sh->val == sp->val){
    			sp->next = sh;
    			sp = sp->next;
    			sh = sh->next;
    		}
    		sp->next = NULL;

    		ListNode* sortedfirst = sortList(d1.next);
    		ListNode* sortedsecond = sortList(sh);
    		
    		return link(sortedfirst,sortedsecond,pivot,sp);
    	}
    }

    ListNode* link(ListNode* a, ListNode* b, ListNode* c, ListNode* d){
		ListNode* aa = a;
		if(!aa){
			d->next = b;
			return c;
		}
		while(aa->next)
			aa = aa->next;
		aa->next = c;
		d->next = b;
		return a;
	}
};


int main(){
	ListNode a1(5);
	ListNode a2(3);
	ListNode a3(4);
	ListNode a4(3);
	ListNode a5(3);
	ListNode a6(3);
	ListNode a7(1);
	a1.next = &a2;
	a2.next = &a3;
	a3.next = &a4;
	a4.next = &a5;
	a5.next = &a6;
	a6.next = &a7;
	Solution soln;
	ListNode* a = soln.sortList(&a1);
	while(a){
		cout<<a->val<<" ";
		a = a->next;
	}
	cout<<endl;
}