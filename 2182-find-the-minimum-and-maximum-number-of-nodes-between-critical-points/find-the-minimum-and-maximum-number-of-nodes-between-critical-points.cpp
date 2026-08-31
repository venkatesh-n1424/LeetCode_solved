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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* cur=head;
        vector<int> list;
        while(cur){
            list.emplace_back(cur->val);
            cur=cur->next;
        }
        int n=list.size();
        if(n<2) return vector<int>{-1,-1};
        vector<int> c;
        for(int i=1;i<n-1;i++){
            int curr=list[i],prev=list[i-1],nex=list[i+1];
            if((curr<prev && curr<nex) || (curr>prev && curr>nex)){
                c.emplace_back(i);
            }
        }
        vector<int> res={INT_MAX,0};
        int m=c.size();
        if(m<2) return vector<int>{-1,-1};
        res[1]=c[m-1]-c[0];
        for(int i=1;i<m;i++){
            res[0]=min(res[0],c[i]-c[i-1]);
        }
        return res;
    }
};