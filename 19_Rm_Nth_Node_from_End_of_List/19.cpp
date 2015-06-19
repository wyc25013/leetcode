#include <iostream>

using namespace std;
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
		int count = 0;
		ListNode *tmp1 = head;
		while (1) {
			count++;
			if(tmp1->next != NULL) 
				tmp1 = tmp1->next;
			else 
				break;
		}		   
		if (count == 1) {
			return NULL;
		}

		if (count == n) {
			ListNode *tmp;
			tmp = head;
			head = tmp->next;
			return head;
		}
		//get the node before the node we want to delete
		tmp1 = head;
		while (count - n - 1) {
			tmp1 = tmp1->next;
			count--;
		}   

		ListNode *tmp3;
		if(tmp1->next->next == NULL) {
			tmp3 = tmp1->next;
			tmp1->next = NULL;
		} else {
			tmp3 = tmp1->next;
			tmp1->next = tmp3->next;
		}
	//	tmp1 = NULL;
		return head;
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
	ListNode *tmp = soln.removeNthFromEnd(&one,3);

//	ListNode *tmp = &one;
	while (1){
		cout << tmp->val <<endl;
		if(tmp->next != NULL)
			tmp = tmp->next;
		else
			break;
	} 
	return 0;
}