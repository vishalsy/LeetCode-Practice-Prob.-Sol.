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

    TreeNode* trim(TreeNode* root, int low, int high) {
        if (root==NULL) { 
			
            return root;
        }
        
        if (root->val >= low && root->val <= high) { 
            
            root->left = trim(root->left, low, high);
            root->right = trim(root->right, low, high);
            return root;
        }
        
        if (root->val < low) {
            return trim(root->right, low, high);
        }
            
        
        return trim(root->left, low, high);
    }

    
    
    
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return trim(root,low,high);

    }
};