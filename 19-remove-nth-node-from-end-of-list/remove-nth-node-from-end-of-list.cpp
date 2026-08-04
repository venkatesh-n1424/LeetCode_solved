/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz=0;
        ListNode* cur=head;
        while(cur){
            sz++;
            cur=cur->next;
        }
        if(sz==1){
            return nullptr;
        }
        int pos=sz-n+1;
        cur=head;
        if(pos==1){
            head=cur->next;
            cur->next=nullptr;
            return head;
        }
        ListNode* prev=NULL;
        while(--pos){
            prev=cur;
            cur=cur->next;
        }
        prev->next=cur->next;
        cur->next=nullptr;
        return head;
    }
};