#include <iostream>
using namespace std;
  
struct ListNode {
  	int val;
  	ListNode *next;
  	ListNode(int x) : val(x), next(NULL) {}
};
 
	class Solution {
	public:
	    ListNode* deleteDuplicates(ListNode* head) {
	    	if(!head || !head->next)
	    		return head;
	        while(head && head->next && head->val == head->next->val){
	        	while(head && head->next && head->val == head->next->val)
	        		head = head->next;
	        	head = head->next;	
	        }
	        ListNode* prev = head;
	        if(!head || !head->next)
	        	return head;

	        ListNode* cur = head->next;

	        while(cur && cur->next){
	        	if(cur->val == cur->next->val){
	        		while(cur && cur->next && cur->val == cur->next->val)
	        			cur = cur->next;
	        		prev->next = cur->next;
	        		cur = prev->next;
	        	}else{
	        		cur = cur->next;
	        		prev = prev->next; 
	        	}
	        }
	        return head;
	    }
	};

int main(){
	ListNode one(2);
	ListNode two(2);
	ListNode three(1);
	ListNode four(1);
	one.next = &two;
	two.next = &three;
	three.next = &four;

	Solution soln;
	ListNode* a = soln.deleteDuplicates(&one);
	while(a){
		cout<<a->val<<" ";
		a = a->next;
	}
	cout<<endl;
}