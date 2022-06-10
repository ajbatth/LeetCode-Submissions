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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder,int pre_start,
                     int pre_end,int in_start, int in_end,map<int,int>&mp){
        if(pre_start>pre_end || in_start>in_end)return NULL;
        TreeNode *root=new TreeNode(preorder[pre_start]);
        int idx=mp[preorder[pre_start]];
        int numsleft=idx-in_start;
        root->left=buildTree(preorder,inorder,pre_start+1,pre_end+numsleft,in_start,idx-1,mp);
        root->right=buildTree(preorder,inorder,pre_start+numsleft+1,pre_end,idx+1,in_end,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return buildTree(preorder,inorder, 0,preorder.size()-1, 0,inorder.size()-1, mp );
    }
};