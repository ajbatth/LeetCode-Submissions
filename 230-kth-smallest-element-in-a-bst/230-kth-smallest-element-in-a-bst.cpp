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
     int ans=0;
    bool flag=1;
    int kthSmallest(TreeNode* root, int &k) {
        //if(!flag)return 0;
        if(root==NULL){
            return 0;
        }
        
        kthSmallest(root->left,k);
        k--;
        if(k==0 ){
            
            ans=root->val;
            //flag=0;
            return ans;
        }
        kthSmallest(root->right,k);
        return ans;
        
        
    }
};