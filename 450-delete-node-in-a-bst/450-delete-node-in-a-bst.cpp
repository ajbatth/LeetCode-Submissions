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
    TreeNode* helper(TreeNode* root){
        if(root->left==NULL)return root->right;
        if(root->right==NULL)return root->left;
        TreeNode* right_of_leftTree=root->left;
        
        while(right_of_leftTree->right!=NULL){
            right_of_leftTree=right_of_leftTree->right;
        }
        
        right_of_leftTree->right=root->right;
        return root->left;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)return root;
        if(root->val==key){
            return helper(root);
        }
        TreeNode* curr=root,*prev=root;
        while(curr){
            if( curr->val>=key){
                if(curr->left && curr->left->val==key){
                    curr->left=helper(curr->left);
                    break;
                }
                curr=curr->left;
            }
            else if(curr->val<=key){
                if(curr->right && curr->right->val==key){
                    curr->right=helper(curr->right);
                    break;
                }
                curr=curr->right;
            }
        }
       return root;     
            
    }
};