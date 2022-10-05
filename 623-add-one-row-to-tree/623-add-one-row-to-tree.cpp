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
    TreeNode* add(TreeNode* root, int val, int depth,int dir){
        
        if(depth==1){
            TreeNode *newNode=new TreeNode(val);
            if(dir==0){                
                newNode->left=root;                
            }
            else{
                newNode->right=root;
            }
            return newNode;
        }
        if(root==NULL)return NULL;
        root->left=add(root->left,val,depth-1,0);
        root->right=add(root->right,val,depth-1,1);
        return root;
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        return add(root,val,depth,0);
    }
};