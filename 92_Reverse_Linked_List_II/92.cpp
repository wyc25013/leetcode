#include <iostream>
using namespace std;

struct ListNode {
 	int val;
 	ListNode *next;
 	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m==n)
            return head;
    	int pos = 1;
    	ListNode* tmp = head;
    	while(pos < m-1){
    		tmp = tmp->next;
    		pos++;
    	}
    	ListNode* tail = NULL;
    	if(m==1)
    		head = helper(tmp,tail,pos,m,n);
    	else
    		tmp->next = helper(tmp->next,tail,pos+1,m,n);
    	return head;
    }

    ListNode* helper(ListNode* head, ListNode*& tail, int pos,int m, int n){
    	if(pos == n) {
    		tail = head->next;
    //		cout<<tail<<endl;
    		return head;
    	}
    	ListNode* np = helper(head->next,tail,pos+1,m,n);
    	head->next->next = head;
    	if(pos == m)
    		head->next = tail;
    	else
    		head->next = NULL;
    	return np;
    }
};

int main(){
	ListNode one(1);
	ListNode two(2);
	ListNode three(3);
//	ListNode four(4);
//	ListNode five(5);

	one.next = &two;
	two.next = &three;
//	three.next = &four;
//	four.next = &five;

	Solution soln;
	ListNode* a = soln.reverseBetween(&one,2,3);
	while(a){
		cout<<a->val<<" ";
		a = a->next;
	}
	cout<<endl;
}