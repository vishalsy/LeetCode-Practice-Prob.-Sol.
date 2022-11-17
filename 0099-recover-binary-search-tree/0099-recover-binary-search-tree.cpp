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
    
    
      void Inorder(TreeNode* root,vector<int>&v){
        if(root==NULL) return ;
        Inorder(root->left,v);
        v.push_back(root->val);
        Inorder(root->right,v);
    }
     void find(TreeNode* root,vector<int>&v,int &i){
        if(root==NULL ) return ;
        find(root->left,v,i);
        if(v[i]!=root->val){
            swap(root->val,v[i]);
            i++;
            cout<<i;
        }else{
            i++;
        }
 
        find(root->right,v,i);
    }
    

    
    void recoverTree(TreeNode* root) {
        vector<int>v;
        Inorder(root,v);
        sort(v.begin(),v.end());
        for(auto i:v){
            cout<<i<<" ";
        }
        int k=0;
        find(root,v,k);
    }
};