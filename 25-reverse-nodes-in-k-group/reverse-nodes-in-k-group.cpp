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
    ListNode* rev(ListNode* head){
        ListNode* prev=nullptr,*cur=head,*nex=nullptr;
        while(cur){
            nex=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nex;
        }
        return prev;
    }
    ListNode* findKth(ListNode* head,int k){
        // int cnt=0;
        // while(head){
        //     cnt++;
        //     if(cnt==k) break;
        //     head=head->next;
        // }
        k--;
        while(head && k>0){
            k--;
            head=head->next;
        }
        return head;

    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur=head,*prev = nullptr,*nex=nullptr;
        while(cur){
            ListNode* kth=findKth(cur,k);
            if(!kth){
                if(prev) prev->next=cur;
                break;
            }
            nex=kth->next;
            kth->next=nullptr;
            rev(cur);
            if(cur==head) head=kth;
            else{
                prev->next=kth;
            }
            prev=cur;
            cur=nex;
        }
        return head;
    }
};