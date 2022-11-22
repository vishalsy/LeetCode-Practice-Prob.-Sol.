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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root==NULL) return root;
        
        queue<TreeNode*>q;
        q.push(root);
        int ct=0;
        
        while(!q.empty()){
            int n=q.size();
            int k=0;
            stack<TreeNode*>s;
            vector<int>v;
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                if(ct%2){
                 s.push(node);
                 v.push_back(node->val);
                }
            }
            int i=0;
            while(!s.empty()){
                s.top()->val=v[i];
                s.pop();
                i++;
            }
            cout<<ct<<" ";
            ct++;
            // cout<<ct;
        }
        
        return root;
    }
};