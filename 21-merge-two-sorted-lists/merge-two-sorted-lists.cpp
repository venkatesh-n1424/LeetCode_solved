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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dnode = new ListNode(-1);
        ListNode* l1=list1, *l2=list2, *cur=dnode;
        while(l1 && l2){
            if(l1->val<=l2->val){
                cur->next=l1;
                cur=cur->next;
                l1=l1->next;
            }
            else{
                cur->next=l2;
                cur=cur->next;
                l2=l2->next;
            }
        }
        while(l1){
            cur->next=l1;
            cur=cur->next;
            l1=l1->next;
        }
        while(l2){
            cur->next=l2;
            cur=cur->next;
            l2=l2->next;
        }
        return dnode->next;
    }
};