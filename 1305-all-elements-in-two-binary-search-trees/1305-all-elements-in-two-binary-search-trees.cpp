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
    
    
    
    void get1(TreeNode* root1,vector<int>&ans1){
        if(root1==NULL) return;
        
        get1(root1->left,ans1);
        ans1.push_back(root1->val);
        get1(root1->right,ans1);
        
    }
     void get2(TreeNode* root2,vector<int>&ans2){
        if(root2==NULL) return;
        
        get1(root2->left,ans2);
        ans2.push_back(root2->val);
        get1(root2->right,ans2);
        
    }
    
 
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>ans1,ans2;
        get1(root1,ans1);
        get2(root2,ans2);
        
        for(int i=0;i<ans2.size();i++){
            ans1.push_back(ans2[i]);
        }
        sort(ans1.begin(),ans1.end());
        return ans1;

    }
};