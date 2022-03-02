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
// class Solution {
// public:    
//     ListNode* reverseList(ListNode* head) {
//         if(head==NULL) return head;
//         ListNode *p=NULL,*c=head,*n=head;
//         while(n!=NULL){
//             n=n->next;
//             c->next=p;
//             p=c;
//             c=n;
//         }
//         return p;
        
//     }
// };

class Solution {// 1->2->3->4->5    NULL<-1<-2<-3<-4<-5 
private:                         //             |new head
    ListNode* rev(ListNode* head){
        if(head->next==NULL || head==NULL)return head;
        
        ListNode* newhead=rev(head->next);
        head->next->next=head;
        head->next=NULL;
        return newhead;
        
    }
    
public:    
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)return head;
        return rev(head);
        
    }
};




















