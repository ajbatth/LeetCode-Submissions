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
    int checkBalance(TreeNode* root,bool &flag){
        if(root==NULL)return 0;
        int left=1+checkBalance(root->left,flag);
        int right=1+checkBalance(root->right,flag);
        if(abs(left-right)>1)flag=0;
        return max(left,right);
        
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL)return true;
        bool flag=1;
        checkBalance(root,flag);
        return flag;
    }
};