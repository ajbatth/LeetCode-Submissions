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
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder,int in_start,int in_end,
                   int post_start,int post_end,unordered_map<int,int>&mp){
    if(in_start>in_end ||post_start>post_end)return NULL;
    TreeNode* root=new TreeNode(postorder[post_end]);
    
    int idx=mp[postorder[post_end]];
    int numsright=in_end-idx;
    
    root->right=buildTree(inorder,postorder,idx+1,in_end,post_end-numsright,post_end-1,mp);
    root->left=buildTree(inorder,postorder,in_start,idx-1,post_start,post_end-numsright-1,mp);
    return root;
}
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return buildTree(inorder,postorder, 0,inorder.size()-1, 0,postorder.size()-1,mp);
    }
};