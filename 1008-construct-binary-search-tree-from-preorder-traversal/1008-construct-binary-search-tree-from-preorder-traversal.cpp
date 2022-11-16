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
    TreeNode* bstFromPreorder(vector<int>& p) {
        int i=0;
        int h=INT_MAX;
        return bst(p,i,h);
        
    }
    
    TreeNode* bst(vector<int>&p,int &i,int &h){
        if(i==p.size() || p[i]>h) return NULL;
        
        TreeNode* root=new TreeNode(p[i++]);
        root->left=bst(p,i,root->val);
        root->right=bst(p,i,h);
        
        return root;
        
        
    }
    

    
};