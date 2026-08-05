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
    ListNode* findMiddle(ListNode* head){
        ListNode* s=head;
        ListNode* f=head->next;
        while(f && f->next){
            s=s->next;
            f=f->next->next;
        }
        return s;
    }
    ListNode* sortList(ListNode* head) {
        // if(!head || !head->next) return head;
        // priority_queue<int,vector<int>,greater<int>> pq;
        // ListNode* cur=head;
        // while(cur){
        //     pq.push(cur->val);
        //     cur=cur->next;
        // }
        // ListNode* new_head=new ListNode(pq.top());
        // pq.pop();
        // cur=new_head;
        // while(!pq.empty()){
        //     ListNode* node=new ListNode(pq.top());
        //     cur->next=node;
        //     cur=node;
        //     pq.pop();
        // }
        // return new_head;
        //optimal
        if(!head || !head->next) return head;
        ListNode* middle=findMiddle(head);
        ListNode* lefthead=head,*righthead=middle->next;
        middle->next=nullptr;
        lefthead=sortList(lefthead);
        righthead=sortList(righthead);
        return mergeTwoLists(lefthead,righthead);
    }
};