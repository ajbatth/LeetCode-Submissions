/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void markParent(TreeNode* root, map<TreeNode*,TreeNode*>&parent){
        if(root==NULL)return;
        if(root->left)parent[root->left]=root;
        if(root->right)parent[root->right]=root;
        markParent(root->left,parent);
        markParent(root->right,parent);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        if(root==NULL)return ans;
        map<TreeNode*,TreeNode*>parent;
        markParent(root,parent);
        int count=0;
        queue<TreeNode*>q;
        q.push(target);
        vector<int>visited(501,0);
        visited[target->val]=1;
        while(!q.empty()&&count<k){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                visited[node->val]=1;
                q.pop();
                
                if(node->left && !visited[node->left->val])q.push(node->left);
                if(node->right && !visited[node->right->val])q.push(node->right);
                node=parent[node];
                if(node && !visited[node->val]){
                    q.push(node);                    
                }
            }
            count++;
        }
        if(count==k){
            while(!q.empty()){
                TreeNode* node=q.front();
            q.pop();
            ans.push_back(node->val);
            }
        }
        return ans;
    }
};