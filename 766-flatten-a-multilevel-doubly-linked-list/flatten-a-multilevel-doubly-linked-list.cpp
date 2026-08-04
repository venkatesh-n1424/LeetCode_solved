/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) return head;
        Node* cur=head;
        while(cur){
            if(cur->child){
                Node* t=cur->next;
                cur->next=flatten(cur->child);
                cur->child=NULL;
                cur->next->prev=cur;
                while(cur->next){
                    cur=cur->next;
                }
                if(t){
                cur->next=t;
                t->prev=cur;
                }
            }
                cur=cur->next;
            
        }
        return head;
    }
};