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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
       vector<vector<int>>ans;
       if(root==NULL) return ans;
        
        queue<TreeNode*>q;
        q.push(root);
        bool b=1;
        while(!q.empty()){
            int n=q.size();
            
            vector<int>v(n);
            for(int i=0; i<n; i++)
            {
                TreeNode* node=q.front();
                q.pop();
                
             if(node->left) q.push(node->left);
             if(node->right) q.push(node->right); 
                    
               if(b==1) v[i]=(node->val);
               else v[n-i-1]=(node->val);
            }  
              if(b==0) b=1;
                else b=0;
            
            for(auto i:v){
                cout<<i<<" ";
            }cout<<endl;
            ans.push_back(v);
        }
        
        return ans;
    }
};