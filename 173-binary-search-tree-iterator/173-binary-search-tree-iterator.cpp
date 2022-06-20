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
class BSTIterator {
    stack<TreeNode*>stk;
    TreeNode* curr;
public:
    BSTIterator(TreeNode* root) {
        curr=root;
    }
    
    int next() {
        while(curr!=NULL){
            stk.push(curr);
            curr=curr->left;
        }
        curr=stk.top();
        int res=curr->val;
        stk.pop();
        curr=curr->right;
        return res;
    }
    
    bool hasNext() {
        return !stk.empty() || curr!=NULL;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */