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
    ListNode* dlt(ListNode* &head){
        if(head==NULL || head->next==NULL)return head;
        ListNode* base=head,*c=head->next;
        bool flag=0;
        while(c!=NULL && c->val==base->val){
            flag=1;
            ListNode* del=c;
            
            c=c->next;
            delete del;
        }
        if(flag){
            ListNode* del=head;
            head=c;
            delete del;
            dlt(head);
        }
        else{
            dlt(head->next);
        }
        return head;
    }
public:
    ListNode* deleteDuplicates(ListNode* head) {
        return dlt(head);
    }
};