#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//make it in place but the code is ugly
class Solution {
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		int proceed = 0;
		int count1 = 0;
		int count2 = 0;
		ListNode *tmp = l1;
		ListNode *extra = new ListNode(0);
		while(tmp != NULL) {
			count1++;
			tmp = tmp->next;
		}
        tmp = l2;
		while(tmp != NULL) {
			count2++;
			tmp = tmp->next;
		}
        
		if(count1>count2){
			tmp = l1;
			while (l2!= NULL) {
				int t = (tmp->val + l2->val + proceed)%10;	
				proceed = (tmp->val + l2->val + proceed)/10;
				tmp->val = t;
				tmp = tmp->next;
				l2 = l2->next;	
			}
			while (tmp->next != NULL) {
				int t = (tmp->val + proceed)%10;	
				proceed = (tmp->val + proceed)/10;
				tmp->val = t;
				tmp = tmp->next;
			}
			int t = (tmp->val + proceed)%10;	
			proceed = (tmp->val + proceed)/10;
			tmp->val = t;
			if(proceed){
				extra->val = proceed;
				tmp->next = extra;
			}
			return l1;
		}
		else if (count2 > count1){
			tmp = l2;
			while (l1!= NULL) {
				int t = (l1->val + tmp->val + proceed)%10;	
				proceed = (l1->val + tmp->val + proceed)/10;
				tmp->val = t;
				l1 = l1->next;
				tmp = tmp->next;	
			}
			while (tmp->next != NULL) {
				int t = (tmp->val + proceed)%10;	
				proceed = (tmp->val + proceed)/10;
				tmp->val = t;
				tmp = tmp->next;
			}

			int t = (tmp->val + proceed)%10;	
			proceed = (tmp->val + proceed)/10;
			tmp->val = t;
			if(proceed){
				extra->val = proceed;
				tmp->next = extra;
			}
			return l2;
		}
		else {
			tmp = l2;
			while (tmp->next != NULL) {
				int t = (tmp->val + l1->val + proceed)%10;	
				proceed = (tmp->val + l1->val + proceed)/10;
				tmp->val = t;
				tmp = tmp->next;
				l1 = l1->next;
			}

			int t = (tmp->val + l1->val + proceed)%10;	
			proceed = (tmp->val + l1->val + proceed)/10;
			tmp->val = t;
			if(proceed){
				extra->val = proceed;
				tmp->next = extra;
			}
			return l2;
		}
	}
};


int main(){
	Solution soln;
	ListNode a1(2);
	ListNode a2(3);
	ListNode a3(4);
	ListNode b1(3);
	ListNode b2(3);
	ListNode b3(3);
//	ListNode b4(3);
	a1.next = &a2;
	a2.next = &a3;
	b1.next = &b2;
	b2.next = &b3;
//	b3.next = &b4;

	ListNode *result = soln.addTwoNumbers(&a1,&a1);
	int res = 0;
	int weight = 1;
	while (result != NULL) {
		res+= weight*result->val;
		result = result->next;
		weight*= 10;
	}
	cout << res <<endl;
	return 0;
}