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
    int ans=0;
    pair<int,int>equal(TreeNode* root){
        if(root==NULL) return {0,0} ;
        int sum=root->val;
        int ct=1;
        auto l=equal(root->left);
        auto r=equal(root->right);
        sum+=l.first+r.first;
        ct+=l.second+r.second;
        if((sum/ct)==root->val)
        {
            ans++;
        }
        // if((sum+l.first+r.first)/(ct+l.second+r.second))
        // {
        //     ans++;
        // }
        return {sum,ct};
    }
    
    
    int averageOfSubtree(TreeNode* root) {
        // int ans=0;
        // int ct=0;
        // int sum=0;
        equal(root);
        return ans;
    }
};