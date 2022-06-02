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
public:
    void PostOrder(TreeNode* root,vector<int>&v){
        if(root==NULL){
            return ;
        }
        PostOrder(root->left,v);
        PostOrder(root->right,v);
        v.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>v;
        stack<TreeNode*>st;
        if(root==NULL)return v;
        st.push(root);
        while(!st.empty()){
            TreeNode *node=st.top();
            st.pop();
            v.push_back(node->val);
            
            if(node->left){
                st.push(node->left);
            }
            if(node->right){
                st.push(node->right);
            }
        }
        reverse(v.begin(),v.end());
        return v;
    }
};