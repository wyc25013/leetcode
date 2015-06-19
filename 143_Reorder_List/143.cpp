#include <iostream>
#include <unordered_map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head) return;
        if(!head->next) return;
//        ListNode* pretail = head;
        unordered_map<int,ListNode*> map;
		ListNode* tail = head;
		map[0] = head;
		int count = 0;
		while(tail->next){
			tail = tail->next;
			count++;
			map[count] = tail;
		}

		helper(head,map,count);
    }

    void helper(ListNode* start, unordered_map<int,ListNode*>& map, int end){
    	if(start->next == map[end] || start == map[end]) return;
    	ListNode* next = start->next;
		start->next = map[end];
		map[end]->next = next;
		map[end-1]->next = NULL;
		helper(next,map,end-1);
    }
};

/* recursive solution
 * no need for extra space
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL)  return;
        bool flag = false;
        reOrder(flag, &head, head);
    }
private:
    void reOrder(bool& flag , ListNode** head, ListNode* tail){
        if(tail==NULL)  return;
        reOrder(flag,head,tail->next);

        if(!flag){
            if((*head)->next==tail || (*head) == tail){
                tail->next = NULL;
                flag = true; // break chaining
                return;
            }
            tail->next = (*head)->next;
            (*head)->next = tail;
            *head = tail->next;
        }
    }
};
*/
int main(){
	ListNode one(1);
	ListNode two(2);
	ListNode three(3);
	ListNode four(4);
	ListNode five(5);
	one.next = &two;
	two.next = &three;
	three.next = &four;
	four.next = &five;

	Solution soln;
	soln.reorderList(&one);
	ListNode* a = &one;
	while(a){
		cout<<a->val<<" ";
		a = a->next;
	}
	cout<<endl;
}