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
    ListNode* middle(ListNode* head){
        ListNode* s=head,*f=head;
        while(f->next && f->next->next){
            s=s->next;
            f=f->next->next;
        }
        ListNode* mid=s->next;
        s->next=nullptr;
        return mid;
    }
    ListNode* rev(ListNode* head){
        ListNode* cur=head,*nex=nullptr,*prev=nullptr;
        while(cur){
            nex=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nex;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(!head->next) return;
        // TC-O(n) SC-O(n)
        // vector<int> arr;
        // ListNode* cur=head;
        // while(cur){
        //     arr.emplace_back(cur->val);
        //     cur=cur->next;
        // }
        // int n=arr.size();
        // cur=head;
        // int i=0,j=n-1;
        // while(i<j){
        //     cur->val=arr[i++];
        //     cur=cur->next;
        //     cur->val=arr[j--];
        //     cur=cur->next;
        // }
        // if(n&1) cur->val=arr[i];
        //TC-O(n) Sc-O(1)
        ListNode* mid=middle(head);
        ListNode* cur1=head,*cur2=rev(mid);
        ListNode* n1=nullptr,*n2=nullptr;
        while(cur1 && cur2){
            n1=cur1->next;
            n2=cur2->next;
            cur2->next=n1;
            cur1->next=cur2;
            cur1=n1;
            cur2=n2;
        }
    }
};