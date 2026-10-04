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
    void reorderList(ListNode* head) {
        // TC-O(n) SC-O(n)
        vector<int> arr;
        ListNode* cur=head;
        while(cur){
            arr.emplace_back(cur->val);
            cur=cur->next;
        }
        int n=arr.size();
        cur=head;
        int i=0,j=n-1;
        while(i<j){
            cur->val=arr[i++];
            cur=cur->next;
            cur->val=arr[j--];
            cur=cur->next;
        }
        if(n&1) cur->val=arr[i];
    }
};