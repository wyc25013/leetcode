#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
		ListNode dummy(-1);
		dummy.next = head;
		ListNode* pre = &dummy;
		while(head){
			if(head->val == val){
				pre->next = head->next;
				head ->next = NULL;
				head = pre->next;
			}else{
				head = head->next;
				pre = pre->next;
			}
			
		}        
		return dummy.next;
    }
};