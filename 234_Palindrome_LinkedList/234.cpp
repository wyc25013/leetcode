/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* walker = &dummy;
        ListNode* runner = &dummy;
        while(walker && runner && runner->next){
            walker = walker->next;
            runner = runner->next->next;
        }
        ListNode* sh = walker->next;
//        walker->next = NULL;
        
        ListNode* rsh = reverseList(sh);
        while(rsh && head){
            if(rsh->val!=head->val)
                return false;
            else{
                rsh = rsh->next;
                head = head->next;
            }
        }
        return true;
    }
    
    ListNode* reverseList(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* prev = head;
        ListNode* cur = head->next;
        head->next = NULL;
        while(cur){
            ListNode* tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        return prev;
    }
};