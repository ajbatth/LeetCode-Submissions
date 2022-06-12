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
    void morris(TreeNode* root, vector<int>&v){
        TreeNode* curr=root;
        while(curr!=NULL){
            if(curr->left){
                TreeNode *pre=curr->left;
                while(pre->right && pre->right!=curr){
                    pre=pre->right;                    
                }
                if(pre->right==NULL){
                        pre->right=curr;
                        curr=curr->left;
                    }
               if(pre->right==curr){
                        pre->right=NULL;
                        v.push_back(curr->val);
                        curr=curr->right;                        
                    }
                
            }
            else{
                v.push_back(curr->val);
                curr=curr->right;
            }
        }
    }
    
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
        morris(root,v);
        return v;
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