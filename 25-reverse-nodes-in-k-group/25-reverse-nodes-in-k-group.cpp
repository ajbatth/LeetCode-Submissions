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
private:
    ListNode* rev(ListNode* head, ListNode* e){
        if( head==e)return head;
        
        ListNode* newhead=rev(head->next,e);
        head->next->next=head;
        head->next=NULL;
        return newhead;
        
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
         int K=k;
        if(head==NULL || k==1||head->next==NULL) return head;
        ListNode *s=head,*e=head;
        
        k--;
        while(k--){
            e=e->next;
            if(e==NULL) return head;
        }
        ListNode* newhead=e->next;
        
        rev(s,e);
        
        ListNode* rev_head=reverseKGroup(newhead,K);
        s->next=rev_head;
        return e;
    }
};

