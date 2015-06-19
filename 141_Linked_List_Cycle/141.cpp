#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> vi;
        while(head){
            if(vi.find(head) == vi.end())
                vi.insert(head);
            else
                return true;
            head = head->next;
        }
        return false;
    }
};
/* Use two pointers, walker and runner.
 * walker moves step by step. runner moves two steps at time.
 * if the Linked List has a cycle walker and runner will meet at some point.
  
public boolean hasCycle(ListNode head) {
    if(head==null) return false;
    ListNode walker = head;
    ListNode runner = head;
    while(runner.next!=null && runner.next.next!=null) {
        walker = walker.next;
        runner = runner.next.next;
        if(walker==runner) return true;
    }
    return false;
}

*/

    