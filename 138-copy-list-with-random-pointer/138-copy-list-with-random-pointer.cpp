// /*
// // Definition for a Node.
// class Node {
// public:
//     int val;
//     Node* next;
//     Node* random;
    
//     Node(int _val) {
//         val = _val;
//         next = NULL;
//         random = NULL;
//     }
// };
// */

// class Solution {
// public:
//     Node* copyRandomList(Node* head) {
//         Node *c=head,*n=head;
//         while(c!=NULL){
//             Node *newNode=new Node(1);
//             n=n->next;
//             newNode->val=c->val;
//             newNode->next=c->next;
//             c->next=newNode;
//             c=c->next->next;
//         }
//         c=head;
//         while(c!=NULL){
//             if(c->random==NULL){
//                 c->next->random=c->random;
//             }
//             else
//             c->next->random=c->random->next;
//             c=c->next->next;
//         }
//         c=head;
//         Node *dummy=new Node(-1),*tail=dummy;
//         while(c!=NULL){
//             tail->next=c->next;
//             c->next=c->next->next;
//             c=c->next;
//             tail=tail->next;
//         }
//         return dummy->next;
        
//     }
// };
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* p=head;
        while(p!=NULL){
            Node* temp=new Node(p->val);
            temp->next=p->next;
            p->next=temp;
            p=temp->next;
        }
        p=head;
        while(p!=NULL){
            if(p->random==NULL)
             p->next->random=NULL;
            else
            p->next->random=p->random->next;
            p=p->next->next;
        }
        Node* new_head=new Node(0),*tail=new_head;
        p=head;
        while(p!=NULL){
            tail->next=p->next;
            tail=tail->next;
            p->next=tail->next;
            p=p->next;
        }
        return new_head->next;
    }
};





















