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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        priority_queue<int,vector<int>,greater<int>> pq;
        ListNode* cur=head;
        while(cur){
            pq.push(cur->val);
            cur=cur->next;
        }
        ListNode* new_head=new ListNode(pq.top());
        pq.pop();
        cur=new_head;
        while(!pq.empty()){
            ListNode* node=new ListNode(pq.top());
            cur->next=node;
            cur=node;
            pq.pop();
        }
        return new_head;
    }
};