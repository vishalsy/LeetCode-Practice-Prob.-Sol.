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
         s.insert(root->val);
        if(root->left!=NULL){
            root->left->val=2*root->val+1;
           build(root->left);
        }
        if(root->right!=NULL){
            root->right->val=2*root->val+2;
           build(root->right);
        }
        
    }
    

    unordered_set<int>s;
    
    FindElements(TreeNode* root) {
        root->val=0;
        build(root);
        
 
    }
    
    bool find(int target) {
        if(s.find(target)!=s.end()) return true;
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */