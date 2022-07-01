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
// class Solution {
// public:
//     bool isValidBST(TreeNode* root, long min, long max) {
//         if(root==NULL)return 1;
//         bool flag=1;
//         if(root->val<=min || root->val>=max)return 0;
//         bool left=1,right=1;
//         left=isValidBST(root->left,min,root->val);
//         right=isValidBST(root->right,root->val,max);
//         return flag&left&right;
//     }
//     bool isValidBST(TreeNode* root){
//         return isValidBST( root,LONG_MIN,LONG_MAX );
//     }
// };

class Solution {
    TreeNode* prev; // Node to store val from last visited inorder node
    public:
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
            return true;
        else
        {
            if(!isValidBST(root->left))
                return false;
            if(prev!=NULL && root->val <= prev->val)
                return false;
            prev=root;
            
            return isValidBST(root->right);
            
        }
    }
};