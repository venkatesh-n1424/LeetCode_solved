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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res=new ListNode(-1);
        ListNode* cur=res;
        int carry=0;
        while(l1 && l2){
            int sum=l1->val+l2->val+carry;
            carry=sum/10;
            ListNode* node=new ListNode(sum%10);
            cur->next=node;
            cur=cur->next;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1){
            int sum=l1->val+carry;
            carry=sum/10;
            ListNode* node=new ListNode(sum%10);
            cur->next=node;
            cur=cur->next;
            l1=l1->next;
        }
        while(l2){
            int sum=l2->val+carry;
            carry=sum/10;
            ListNode* node=new ListNode(sum%10);
            cur->next=node;
            cur=cur->next;
            l2=l2->next;
        }
        if(carry){
            ListNode* node=new ListNode(carry);
            cur->next=node;
            cur=cur->next;
        }
        cur=res->next;
        // res->next=nullptr;
        // free(res);
        return cur;
    }
};
