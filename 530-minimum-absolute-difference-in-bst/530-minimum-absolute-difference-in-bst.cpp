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
     void help(TreeNode* root,int &ans,TreeNode* &pre){
        if(root->left){
            help(root->left,ans,pre);
        }
        if(pre){
            ans=min(ans,abs(pre->val - root->val));
        }
         pre=root;
        if(root->right){
            help(root->right,ans,pre);
        }
    }
    int getMinimumDifference(TreeNode* root) {
        int ans=1e9;
        TreeNode* pre=NULL;
        help(root,ans,pre);
        return ans;
    }
};