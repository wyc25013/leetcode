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
    	ListNode* tmp = head;
        while(tmp && tmp->next){
        	if(tmp->val == tmp->next->val){
        		tmp->next = tmp->next->next;
        	//	tmp->next->next = NULL;
        	}else
        		tmp = tmp->next;
        }
        return head;
    }
};

int main(){
	ListNode one(1);
	ListNode two(1);
	ListNode three(1);
	one.next = &two;
	two.next = &three;

	Solution soln;
	ListNode* a = soln.deleteDuplicates(&one);
	while(a){
		cout<<a->val<<" ";
		a = a->next;
	}
	cout<<endl;
}