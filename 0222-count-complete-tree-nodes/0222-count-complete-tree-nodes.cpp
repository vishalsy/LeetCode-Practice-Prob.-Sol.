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
    int ct(TreeNode* node){
        if(node==NULL){
            return 0;
        }
        // ct++;
         int l= ct(node->left);
         int r= ct(node->right);
        return l+r+1;
    }
    
    
   
    
    
    
    int countNodes(TreeNode* root) {
       if(root==NULL) return 0;
        return ct(root);
    }
};