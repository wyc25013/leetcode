#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return NULL;
    	ListNode dummy(-1);
        ListNode* runner = &dummy; dummy.next = head;
    	for(int i = 0; i < k; i++){
    		if(runner->next)
    			runner = runner->next;
    		else
    			return head;
    	}
    	dummy.next = runner;
    	if(!runner->next){
    		reverse(head);
    		return dummy.next;
    	}else{
    		ListNode* nh = runner->next;
    		runner->next = NULL;
    		reverse(head)->next = reverseKGroup(nh,k);
    	}
    	return dummy.next;
    }
	
    ListNode* reverse(ListNode* node){
    	if(!node || !node->next) return node;
    	ListNode* next = reverse(node->next);
    	next->next = node;
    	node->next = NULL;
    	return node;
    }
};

int main(){
	ListNode a1(1);
	ListNode a2(2);
	ListNode a3(3);
	ListNode a4(4);
	ListNode a5(5);
	ListNode a6(6);
	ListNode a7(7);
	a1.next = &a2;
	a2.next = &a3;
	a3.next = &a4;
	a4.next = &a5;
	a5.next = &a6;
	a6.next = &a7;
	Solution soln;
	ListNode* a = soln.reverseKGroup(&a1,3);
	while(a){
		cout<<a->val<<" ";
		a = a->next;
	}
	cout<<endl;
}