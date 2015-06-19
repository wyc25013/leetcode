/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
using namespace std; 

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	if(l1 == NULL)
    		return l2;
    	else if(l2 == NULL)
    		return l1;
    	int head = l1->val > l2->val ? l2->val : l1->val;
    	ListNode *result = new ListNode(head);
    	if(l1->val > l2->val)
    		l2 = l2->next;
    	else
    		l1 = l1->next;

    	ListNode* tmp;
    	tmp = result;
        while(l1 != NULL && l2 != NULL){
        	int nextval = l1->val > l2->val ? l2->val : l1->val;
    		ListNode *next = new ListNode(nextval);
    		if(l1->val > l2->val)
    			l2 = l2->next;
    		else
    			l1 = l1->next;
        	tmp->next = next;
        	tmp = tmp->next;
        }
        if(l1 == NULL)
        	tmp->next = l2;
        else
        	tmp->next = l1;
		return result;
    }
};

int main(){
	Solution soln;
	ListNode one(1);
//	ListNode two(2);
//	ListNode three(3);
//	ListNode four(4);
//	ListNode five(5);

//	one.next = &two;
//	two.next = &three;
//	three.next = &four;
//	four.next = &five;

	ListNode one2(2);
//	ListNode two2(3);
//	ListNode three2(5);
//	ListNode four2(7);
//	ListNode five2(9);

//	one2.next = &two2;
//	two2.next = &three2;
//	three2.next = &four2;
//	four2.next = &five2;

	ListNode* result = soln.mergeTwoLists(&one,&one2);
	while(result != NULL){
		cout << result->val <<" ";
		result = result->next;
	}
	cout << endl;
}