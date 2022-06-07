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
    int countGoodNodes(TreeNode* root,int maxi){
        if(root==NULL)return 0;
        int c1=countGoodNodes(root->left,max(maxi,root->val));
        int c2=countGoodNodes(root->right,max(maxi,root->val));
        if(root->val>=maxi)return 1+c1+c2;
         return c1+c2;
    }
    int goodNodes(TreeNode* root) {
        return countGoodNodes(root,INT_MIN);
    }
};