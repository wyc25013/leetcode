#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/* iterative solution 
 *
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    	if(head == NULL)
    		return head;
    	ListNode* prev = NULL;
    	ListNode* next;
		while(head->next){
			next = head->next;
			head->next = prev;
			prev = head;
			head = next; 
		}
		head->next = prev;
		return head;
    }
};
*/

// recursive solution
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;   // case proof and recursion exit conditon
        ListNode *np = reverseList(head->next);
        head->next->next = head;         // make the next node point back to the node itself
        head->next = NULL;               // destroy the former pointer
        return np;
    }
};

int main(){
	ListNode one(1);
	ListNode two(2);
	ListNode three(3);
	ListNode four(4);

	one.next = &two;
	two.next = &three;
	three.next = &four;

	Solution soln;
	ListNode* a = soln.reverseList(&one);
	while(a){
		cout<<a->val<<" ";
		a = a->next;
	}
	cout<<endl;
}