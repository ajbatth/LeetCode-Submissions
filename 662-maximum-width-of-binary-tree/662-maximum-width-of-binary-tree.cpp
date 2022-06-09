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
    int widthOfBinaryTree(TreeNode* root) {
        long long width=0;
        if(root==NULL)return width;
        queue<pair<TreeNode*,int>>q;
        q.push({root,1});
        while(!q.empty()){
            int n=q.size();
            long long first,last;
           
            for(int i=0;i<n;i++){
                TreeNode* node=q.front().first;
                int s_no=q.front().second;
                q.pop();
                if(i==0)first=s_no;
                if(i==n-1)last=s_no;
                if(node->left)q.push({node->left,(s_no-first)*2LL+1});
                if(node->right)q.push({node->right,(s_no-first)*2LL+2});
            }
            width=max(width,last-first+1);
        }
        return width;
    }
};