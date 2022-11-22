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
    // void maxi(vector<int>&v, int a,int b,int &maxi,int &i){
    
    
    TreeNode* cons(vector<int>& v){
      if(v.size()==0) return NULL;
        
        
      int maxi=*max_element(v.begin(),v.end());
        int k=-1;
        for(int i=0;i<v.size();i++){
            if(maxi==v[i]){
                k=i;
                break;
            }
        }
        TreeNode* root=new TreeNode(maxi);
        
        vector<int>p(v.begin(),v.begin()+k);
        vector<int>s(v.begin()+k+1,v.end());
        
        root->left=cons(p);
        root->right=cons(s);

        return root;
    }
    
    
    
    
    
    
    
    
    TreeNode* constructMaximumBinaryTree(vector<int>& v) {
         return cons(v);
    }
};