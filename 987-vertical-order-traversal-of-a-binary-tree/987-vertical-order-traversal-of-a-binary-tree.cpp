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
    void pre(TreeNode* root,map<int,map<int,multiset<int>>>&mp,int row,int col){
        if(root==NULL)return;
        mp[row][col].insert(root->val);
        pre(root->left,mp,row-1,col+1);
        pre(root->right,mp,row+1,col+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>mp;
        pre(root,mp,0,0);
        vector<vector<int>>ans;
        for(auto it1:mp){
            vector<int>v;
            for(auto it2:it1.second){
                for(auto it3:it2.second){
                    v.push_back(it3);
                }
            }
            ans.push_back(v);
        }
        
        return ans;
        
    }
};