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
    
    void s(TreeNode* node,int &sum,int h,int k){
        if(node==NULL ) return;
        if(k==h){
            sum+=node->val;
            return;
        } 
        cout<<k<<" ";
        s(node->left,sum,h,k+1);
        s(node->right,sum,h,k+1);
        k-=1;   
    }
    
    
    
    
    
    
    int he(TreeNode* root){
        if(root==NULL) return 0;
        
        int l=he(root->left);
        int r=he(root->right);
        return 1+max(l,r);
    }
    
 
    int deepestLeavesSum(TreeNode* root) {
      
     int h=he(root);
        // cout<<h;
        int sum=0;
        int k=1;
        s(root,sum,h,k);
        return sum;
    }
};