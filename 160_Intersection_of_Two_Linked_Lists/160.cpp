#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//space o(n)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;
        if(a==b) return headA;
        if(!a || !b) return NULL;
        unordered_set<ListNode*> ss;
        while(a){
        	ss.insert(a);
        	a = a->next;
        }
        while(b){
        	if(ss.find(b) != ss.end())
        		return b;
        	b = b->next;
        }
        return NULL;
    }
};

//space o(1)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;
        if(a==b) return headA;
        if(!a || !b) return NULL;
        int i,j;
        for(i = 0; a; i++)
            a = a->next;
        for(j = 0; b; j++)
            b = b->next;
        if(a!=b) return NULL;
    	a = headA; b = headB;
    	if(i>j)
    		for(;i!=j;j++)
    			a = a->next;
    	else
    		for(;i!=j;j--)
    			b = b->next;

    	while(a){
    		if(a==b) return a;
    		a = a->next;
    		b = b->next;
    	}
    	return NULL;
    }
};