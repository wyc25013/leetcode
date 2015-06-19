#include <iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
    	if(head == NULL)
    		return head;
    	ListNode* headNode = head->next;
    	if(headNode == NULL)
    		return head;
    	else{
    		head->next = headNode->next;
    		headNode->next = head;
    	}

    	ListNode* currentNode = head->next; 

    	while(currentNode != NULL && currentNode->next != NULL){
    		ListNode* nextNode = currentNode->next;
    		head->next = nextNode;
			currentNode->next = nextNode->next;
			nextNode->next = currentNode;
			head = currentNode;
			currentNode = currentNode->next;
    	}
		
		return headNode;
    }
};

int main(){
	Solution soln;
	ListNode one(4);
	ListNode two(1);
	ListNode three(3);
	ListNode four(2);
	ListNode five(5);
	ListNode six(6);

	one.next = &two;
	two.next = &three;
	three.next = &four;
	four.next = &five;
	five.next = &six;

	ListNode* ret = soln.swapPairs(&one);
	while(ret != NULL){
		cout<<ret->val<<" ";
		ret = ret->next;
	}
	cout<<endl;
}