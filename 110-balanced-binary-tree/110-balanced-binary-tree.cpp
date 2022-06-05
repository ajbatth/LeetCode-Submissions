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
    int getHeight(TreeNode* root, bool& balance){
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return 1;
        int left = getHeight(root->left,balance) ;
        int right = getHeight(root->right, balance);
        if(abs(left-right)>1) balance=0;
        return max(left,right)+1;
    }
public:
    bool isBalanced(TreeNode* root) {
        bool balance =1;
        getHeight(root,balance);
        return balance;
    }
};