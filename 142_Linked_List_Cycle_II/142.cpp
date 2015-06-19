#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return NULL;
        ListNode* walker = head;
        ListNode* runner = head;
        while(runner->next!=NULL && runner->next->next!=NULL) {
            walker = walker->next;
            runner = runner->next->next;
            if(walker==runner){
                walker = head;
                while(walker != runner){
                    walker = walker->next;
                    runner = runner->next;
                }
                return walker;
            }
        }
        return NULL;
    }
};
// 1...i...x...j
//     ^       |
//     |       |
//     ---------
// 2x-(i-1) = a(j-i+1)