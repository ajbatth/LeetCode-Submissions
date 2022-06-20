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
    TreeNode* bst(vector<int>& preorder,int start,int end){
        if(start>end)return NULL;
        int limit=start;
        for(int i=start;i<=end;i++){
            if(preorder[i]<preorder[start])limit=i;
        }
        TreeNode* root=new TreeNode(preorder[start]);
        root->left=bst(preorder,start+1,limit);
        root->right=bst(preorder,limit+1,end);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return bst(preorder,0,int(preorder.size())-1);
    }
};