/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<bits/stdc++.h>
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL)return "";
        string s="";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            
                TreeNode* node=q.front();
                q.pop();
                if(node==NULL){
                    s.append("#,");
                }
                else s.append(to_string(node->val)+',');
                if(node)q.push(node->left);
                if(node)q.push(node->right);
            
        }
        return s;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)return NULL;
        stringstream s(data);
        string ch;
        getline(s , ch , ',');
        TreeNode* root=new TreeNode(stoi(ch));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            
                TreeNode *curr=q.front();
                q.pop();
                getline(s,ch,',');
                if(ch=="#"){
                    curr->left=NULL;
                }
                else{
                    TreeNode* LN=new TreeNode(stoi(ch));
                    curr->left=LN;
                    q.push(LN);
                }
                
                getline(s,ch,',');
                if(ch=="#"){
                    curr->right=NULL;
                    
                }
                else{
                    TreeNode* RN=new TreeNode(stoi(ch));
                    curr->right=RN;
                    q.push(RN);
                }
            
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));