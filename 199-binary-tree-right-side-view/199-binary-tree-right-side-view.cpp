/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void reversePreOrder(TreeNode* root,int level,vector<int>&v){
        if(root==NULL)return;
        if(level==v.size())v.push_back(root->val);
        reversePreOrder(root->right,level+1,v);
        reversePreOrder(root->left,level+1,v);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        reversePreOrder(root,0,ans);
        return ans;
        if(root==NULL)return ans;
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                if(i==n-1)ans.push_back(node->val);
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
        }
        return ans;
    }
};