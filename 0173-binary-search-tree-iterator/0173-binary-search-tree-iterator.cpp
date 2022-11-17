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
class BSTIterator {
public:
    stack<TreeNode*>s;

    BSTIterator(TreeNode* root) {
        bharo(root);
    }
    
    int next() {
        TreeNode* p=s.top();
        s.pop();
        bharo(p->right);
        return p->val;
    }
    
    bool hasNext() {
        if(!s.empty()) return true;
        else return false;
    }
    
    void bharo(TreeNode* node){
        if(node==NULL) return;
         
        s.push(node);
        node=node->left;
        bharo(node);
        
    }
    
    
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */