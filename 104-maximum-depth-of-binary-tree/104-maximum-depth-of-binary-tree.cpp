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
    int depth(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int Left=1+depth(root->left);
        int Right=1+depth(root->right);
        return max(Left,Right);
    }
    int maxDepth(TreeNode* root) {
        //return depth(root);
        queue<TreeNode*>q;
        if(root==NULL)return 0;
        q.push(root);
        int d=0;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                q.pop();
            }
            d++;
        }
        return d;
    }
};