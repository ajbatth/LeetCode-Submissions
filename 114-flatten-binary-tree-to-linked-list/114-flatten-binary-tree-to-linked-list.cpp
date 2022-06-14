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
    
    //Reecursive    right-left-root
    void flatten(TreeNode* root,TreeNode* &prev){
        if(root==NULL)return;
        
        flatten(root->right,prev);
        flatten(root->left,prev);
        
        root->right=prev;
        prev=root;
        root->left=NULL;
    }
public:
    void flatten(TreeNode* root) {
        TreeNode*prev=NULL;
        //flatten(root,prev);
        
        //Iterative using stack
        stack<TreeNode*>st;
        if(root==NULL)return;
        st.push(root);
        while(!st.empty()){
            TreeNode* curr=st.top();
            st.pop();
            if(curr->right)st.push(curr->right);
            if(curr->left)st.push(curr->left);
            if(!st.empty())
                curr->right=st.top();
            curr->left=NULL;
        }
        
    }
};