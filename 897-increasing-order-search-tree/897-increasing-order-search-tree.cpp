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
    TreeNode *ROOT=new TreeNode(),*tail=ROOT;
    void f(TreeNode *root){
        if(root==NULL)return;
        f(root->left);
        TreeNode *n= new TreeNode(root->val);
        tail->right=n;
        tail=tail->right;
        f(root->right);
        
    }
    TreeNode* increasingBST(TreeNode* root) {
        f(root);
        return ROOT->right;
    }
};