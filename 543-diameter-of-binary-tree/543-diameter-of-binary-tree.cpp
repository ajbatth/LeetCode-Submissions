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
    int dia(TreeNode* root,int &D){
        if(root==NULL)return 0;
        int left=dia(root->left,D);
        int right=dia(root->right,D);
        D=max(D,left+right);
        return max(left,right)+1;
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        dia(root,diameter);
        return diameter;
    }
};