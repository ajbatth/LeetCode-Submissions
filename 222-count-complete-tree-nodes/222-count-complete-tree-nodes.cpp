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
    int leftHeight(TreeNode* root){
        int count=0;
        while(root){
            count++;
            root=root->left;
        }
        return count;
    }
    int rightHeight(TreeNode* root){
        int count=0;
        while(root){
            count++;
            root=root->right;
        }
        return count;
    }
public:
    int countNodes(TreeNode* root) {
        if(root==NULL)return 0;
        int LH=leftHeight(root);
        int RH=rightHeight(root);
        
        if(LH==RH)return (1<<LH)-1;
        return countNodes(root->left)+countNodes(root->right)+1;
    }
};












