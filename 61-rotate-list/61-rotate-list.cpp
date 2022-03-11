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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL||k==0) return head;
        ListNode *it=head,*p=NULL,*c=head;
        int size=0;
        while(it!=NULL){
            size++;
            it=it->next;
        }
        
        k=k%size;
        if(k==0)return head;
        //cout<<size;
       int diff=size-k;
        while(diff--){
            p=c;
            c=c->next;
        }
        it=head;
        head=c;
        p->next=NULL;
        while(c->next!=NULL){
            c=c->next;
        }
        c->next=it;
        return head;
        
    }
};