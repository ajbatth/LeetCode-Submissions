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
bool cmp(TreeNode* a,TreeNode*b){
    return a->val < b->val;
}
class Solution {
public:
    void in(TreeNode* root,vector<TreeNode*>&v){
        if(root==NULL)return;
        in(root->left,v);
        v.push_back(root);
        in(root->right,v);
    }
    void recoverTree(TreeNode* root) {
        vector<TreeNode*>v;
        in(root,v);
        vector<TreeNode*>sv=v;
        sort(sv.begin(),sv.end(),cmp);
        int n=v.size();
        
        for(int i=0;i<n;i++){
            if(v[i]->val!=sv[i]->val){
                swap(v[i]->val,sv[i]->val);
                break;
            }
        }
    }
};