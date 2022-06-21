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
    void recover(TreeNode* root, TreeNode* &first, TreeNode* &mid, TreeNode* &last,TreeNode* &prev){
        if(root==NULL)return;
        
        recover(root->left,first,mid,last,prev);
        if(prev!=NULL && prev->val>root->val){
            if(first==NULL){
                first=prev;
                mid=root;
            }
            else{
                last=root;
            }
        }
        prev=root;
        recover(root->right,first,mid,last,prev);
        
        
    }
    
    void recoverTree(TreeNode* root) {
        TreeNode* first=NULL,*mid=NULL,*last=NULL, *prev=NULL;
        recover(root,first,mid,last,prev);
        if(last!=NULL)swap(first->val,last->val);
        else swap(first->val,mid->val);        
    }
};