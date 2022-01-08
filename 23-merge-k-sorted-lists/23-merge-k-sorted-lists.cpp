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
        set<pair<int,ListNode*>>st;
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL)
            st.insert(make_pair(lists[i]->val,lists[i]));
        }
        ListNode* dummy=new ListNode(INT_MIN),*tail=dummy;
        while(st.size()){
            ListNode *c=(st.begin())->second;
            tail->next=c;
            if(c->next!=NULL)
            st.insert(make_pair(c->next->val,c->next));            
            //delete c;
            st.erase(st.begin());
            tail=tail->next;
            
        }
        return dummy->next;
    }
};

// class Solution {
// public:
//     struct compare {
//     bool operator()(const ListNode* l, const ListNode* r) {
//         return l->val > r->val;
//     }
// };
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
        

//     priority_queue<ListNode *, vector<ListNode *>, compare> q;
//     for(auto l : lists) {
//         if(l)  q.push(l);
//     }
//     if(q.empty())  return NULL;

//     ListNode* result = q.top();
//     q.pop();
//     if(result->next) q.push(result->next);
//     ListNode* tail = result;            
//     while(!q.empty()) {
//         tail->next = q.top();
//         q.pop();
//         tail = tail->next;
//         if(tail->next) q.push(tail->next);
//     }
//     return result;
// }
    
// };

