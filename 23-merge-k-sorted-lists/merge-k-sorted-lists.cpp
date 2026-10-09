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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;
        for(int i=0;i<n;i++){
            if(lists[i])
            pq.push({lists[i]->val,lists[i]});
        }
        ListNode* dnode=new ListNode(0);
        ListNode* cur=dnode;
        while(!pq.empty()){
            pair<int,ListNode*> p=pq.top();
            pq.pop();
            if(p.second->next)
            pq.push({p.second->next->val,p.second->next});
            cur->next=p.second;
            cur=cur->next;
        }
        return dnode->next;
    }
};