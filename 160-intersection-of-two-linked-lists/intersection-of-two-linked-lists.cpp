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
    ListNode *solve(ListNode* p,ListNode* q,int &d){
        while(d--){
            p=p->next;
        }
        while(p && q){
            if(p==q) return p;
            p=p->next;
            q=q->next;
        }
        return NULL;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int m=0,n=0;
        ListNode* a=headA;
        ListNode* b=headB;
        while(a){
            m++;
            a=a->next;
        }
        while(b){
            n++;
            b=b->next;
        }
        int d=abs(m-n);
        if(m>=n) return solve(headA,headB,d);
        return solve(headB,headA,d);
    }
};