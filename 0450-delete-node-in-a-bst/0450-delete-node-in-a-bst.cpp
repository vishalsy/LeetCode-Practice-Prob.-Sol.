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
    
    
   TreeNode* find(TreeNode* root){
        if(root->left== NULL) return root->right;
        else if(root->right==NULL) return root->left;
        
         TreeNode* a=root->right;
         TreeNode* b=rightmost(root->left);
         b->right=a;
       cout<<root->val;
       // return root;
     return root->left;
       
    }
    
    
    
    
    TreeNode* rightmost(TreeNode* node){
        if(node->right==NULL) return node;
        
        
        return rightmost(node->right);
    }

    
    
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        TreeNode* ans=root;
        
        if(root->val==key){
            return find(root);
        }

        while(root){
            if(root->val>key){
                if(root->left!=NULL && root->left->val==key )
                {
                    root->left=find(root->left);
                    // cout<<root->left->val<<endl;
                    break;
                }
                else 
                // cout<<root->val<<" ";
                root=root->left; 
                }
            else{
                if(root->right!=NULL && root->right->val==key)
                {    
                    
                      cout<<root->right->val<<endl;
                     root->right=find(root->right);
                    
                    break;
                }else root=root->right;
               }
            
        }
        
       return ans; 
 
    }
};