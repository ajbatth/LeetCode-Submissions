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
    void Inorder(TreeNode *root,vector<int>&v){
        if(root==NULL){
            return;
        }
        Inorder(root->left,v);
        v.push_back(root->val);
        Inorder(root->right,v);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>v;
        stack<TreeNode*>st;
        TreeNode* curr=root;
        while(!st.empty() || curr!=NULL){
            while(curr!=NULL){
                st.push(curr);
                curr=curr->left;
            }
            curr=st.top();
            st.pop();
            v.push_back(curr->val);
            curr=curr->right;
        }
        return v;
        
    }
};