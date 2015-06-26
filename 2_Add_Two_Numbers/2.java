/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode a1 = l1;
        ListNode a2 = l2;
        if(a1==null) return a2;
        if(a2==null) return a1;
        int proceed;
        if(a1.val+a2.val <= 9)
            proceed = 0;
        else
            proceed = 1;
        ListNode ret = new ListNode((a1.val+a2.val)%10);
        ListNode cur = ret;
        a1 = a1.next; a2 = a2.next;
        
        while(a1!=null && a2!=null){
            int v1 = a1.val;
            int v2 = a2.val;
            a1 = a1.next; a2 = a2.next;
            cur.next = new ListNode((proceed+v1+v2)%10);
            cur = cur.next;
            if(v1+v2+proceed <= 9)
                proceed = 0;
            else
                proceed = 1;
        }
        while(a1!=null){
            int v1 = a1.val; a1 = a1.next; 
            cur.next = new ListNode((proceed+v1)%10);
            cur = cur.next;
            if(v1+proceed <= 9)
                proceed = 0;
            else
                proceed = 1;
        }
        while(a2!=null){
            int v2 = a2.val; a2 = a2.next; 
            cur.next = new ListNode((proceed+v2)%10);
            cur = cur.next;
            if(v2+proceed <= 9)
                proceed = 0;
            else
                proceed = 1;
        }
        if(proceed==1)
            cur.next = new ListNode(1);
        return ret;
    }
}