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
    bool isSame(TreeNode* lt,TreeNode*rt){
        if(lt==NULL && rt==NULL)return true;
        if(lt==NULL||rt==NULL)return false;
        if(lt->val!=rt->val)return false;
        return isSame(lt->left,rt->right) && isSame(lt->right,rt->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)return true;
        return isSame(root->left,root->right);
    }
};