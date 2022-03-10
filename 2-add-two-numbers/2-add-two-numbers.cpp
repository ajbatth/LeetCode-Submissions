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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *list1=l1,*list2=l2;
        ListNode *sum=new ListNode(0),*tail=sum;
        int carry=0;
        while(list1!=NULL && list2!=NULL){
            int addition=list1->val + list2->val +carry;
            list1=list1->next;
            list2=list2->next;
            carry=0;
            if(addition>9)carry=1;
            addition=addition%10;
            ListNode *temp=new ListNode(addition);
            tail->next=temp;
            tail=tail->next;
        }
        while((list1!=NULL || carry)&& list2==NULL){
            int addition=0;
            if(list1!=NULL){
                 addition=list1->val + carry;
            list1=list1->next;
            }
            else{
                 addition=carry;
            }
            
            carry=0;
            if(addition>9)carry=1;
            addition=addition%10;
            ListNode *temp=new ListNode(addition);
            tail->next=temp;
            tail=tail->next;
        }
        while((list2!=NULL || carry)&&list1==NULL){
            int addition=0;
            if(list2!=NULL){
                 addition=list2->val + carry;
            list2=list2->next;
            }
            else{
                 addition=carry;
            }
            
            carry=0;
            if(addition>9)carry=1;
            addition=addition%10;
            ListNode *temp=new ListNode(addition);
            tail->next=temp;
            tail=tail->next;
        }
        return sum->next;
        
    }
};