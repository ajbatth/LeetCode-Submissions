/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
void dfsclone(Node* root,Node* original,vector<Node*>&visited){
    for(auto adj:original->neighbors){
        if(visited[adj->val]==NULL){
            Node* child=new Node(adj->val);
            root->neighbors.push_back(child);
            visited[adj->val]=child;
            dfsclone(child,adj,visited);
        }
        else{
            root->neighbors.push_back(visited[adj->val]);
        }
    }
}
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL)return NULL;
       Node* root=new Node(node->val);
        vector<Node*>visited(102,NULL);
        visited[node->val]=root;
        dfsclone(root,node,visited);
        return root;
    }
};