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
    void count(TreeNode* node,int &ct){
        if(node==NULL){
            return ;
        }
        ct++;
        cout<< ct<<" ";
        count(node->left,ct);
        count(node->right,ct);
        
    }
    
    
   
    
    
    
    int countNodes(TreeNode* root) {
       if(root==NULL) return 0;
        int ct=0;
        count(root,ct);
      cout<<ct;        
        return ct;
    }
};