#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
     	ListNode* less = NULL;
     	ListNode* tmp = head;
     	ListNode* prev = head;
     	while(tmp){
     		if(tmp->val < x){
     			if(less){
     			    if(less == prev){
     			        if(tmp != head)
     			            prev = prev->next;
     			        less = tmp;
     			        tmp = tmp->next;
     			        
     			    }else{
     			        prev->next = tmp->next;
         				tmp->next = less->next;
         				less->next = tmp;
     	    			less = tmp;
     		    		tmp = prev->next;
     			    }
     			}else{
     				if(tmp == head){
     					less = head;
     					tmp = tmp->next;
     				}
     				else{
     					prev->next = tmp->next;
     					tmp->next = head;
     					head = tmp;
     					less = head;
     					tmp = prev->next;
     				}
     			}
     		}else{
     			if(tmp != head)
     				prev = prev->next;
     			tmp = tmp->next;
     		}
     	}
     	return head;   
    }
};

int main(){
	ListNode one(1);
	ListNode two(2);
	ListNode three(3);
	ListNode four(4);
	ListNode five(5);
	ListNode six(6);
//	ListNode seven(1);

	one.next = &two;
	two.next = &three;
	three.next = &four;
	four.next = &five;
	five.next = &six;

	Solution soln;
	ListNode* a = soln.partition(&one,6);
	while(a){
		cout<<a->val<<" ";
		a = a->next;
	}
	cout<<endl;
}