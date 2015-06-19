#include <iostream>
using namespace std;

struct ListNode {
 int val;
 ListNode *next;
 ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)
            return head;
            
    	ListNode* tail = head;
    	int cnt = 0;
    	while(tail->next != NULL){
    		tail = tail->next;
    		cnt++;
    	}
    	
    	if(cnt == 0)
    	    return head;
    	if(cnt+1 <= k)
    	    k %= cnt+1;
    	if(k == 0)
            return head;

    	tail = head;
    	for(int i = 0; i < cnt-k; i++){
    		tail = tail->next;
    	}
    	ListNode* newhead = tail->next;
    	tail->next = NULL;
    	ListNode* tmp = newhead;
    	while(tmp->next != NULL){
    		tmp = tmp->next;
    	}
    	tmp->next = head;
    	return newhead;
    	
    }
};