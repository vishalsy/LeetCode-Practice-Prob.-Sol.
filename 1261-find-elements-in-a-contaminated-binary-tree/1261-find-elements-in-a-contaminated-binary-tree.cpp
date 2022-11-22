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
class FindElements {
public:
    void build(TreeNode* root){
   
        if(root->left!=NULL){
            root->left->val=2*root->val+1;
           build(root->left);
        }
        if(root->right!=NULL){
            root->right->val=2*root->val+2;
           build(root->right);
        }
        
    }
     void get(TreeNode* root,vector<int>&ans){
        if(root==NULL) return;
        
        get(root->left,ans);
        ans.push_back(root->val);
        get(root->right,ans);
        
    }

    vector<int>ans;
    
    FindElements(TreeNode* root) {
        root->val=0;
        build(root);
        get(root,ans);
 
    }
    
    bool find(int target) {
        for(int i=0;i<ans.size();i++){
            if(ans[i]==target) return true;
        }
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */