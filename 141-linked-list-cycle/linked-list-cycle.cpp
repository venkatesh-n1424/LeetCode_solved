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
    bool hasCycle(ListNode *head) {
        ListNode *s=head,*f=head;
        if(!head) return head;
        while(true){
            if(f->next==nullptr || f->next->next==nullptr) return false;
            s=s->next;
            f=f->next->next;
            if(s==f) return true;
        }
        return false;
    }
};