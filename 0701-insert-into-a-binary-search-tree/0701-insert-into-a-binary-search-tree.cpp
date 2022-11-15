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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node=root;
        if(node==NULL){
            node= new TreeNode(val);
            return node;
        }
        
        TreeNode* k=NULL;
        while(root){
            if(root->val>val){
                k=root;
                root=root->left;
            }else{
                k=root;
                root=root->right;
            }
        }
        // return k;
        if(k->val<val) k->right=new TreeNode(val);
        else k->left=new TreeNode(val);
        return node;
        
    }
};