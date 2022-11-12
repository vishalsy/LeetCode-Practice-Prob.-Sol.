/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<int>v(m*n,-1);
        vector<vector<int>>ans(m,vector<int>(n,-1));
        
        for(int i=0;i<m*n;i++){
            v[i]=head->val;
            if(head->next==NULL) break;
            else head=head->next;
        }
        
        // for(auto i:v){
        //     cout<<i<<" ";
        // }
        
        int l,r,t,d;
        l=0,t=0,r=n-1,d=m-1;
        int k=0;
        while(l<=r && t<=d){
             for(int i=l;i<=r;i++){
                ans[t][i]=v[k];
                 k++;
                 
            }
            t++;
            // cout<<v[k];
            for(int i=t;i<=d;i++){
                
                ans[i][r]=v[k];
                
                k++;
                
            }
            // cout<<ans[t][r];
            r--;
            if(l>r || t>d) break;
            
            for(int i=r;i>=l;i--){
                // k++;
                ans[d][i]=v[k];
                k++;
            }
            d--;
            
            for(int i=d;i>=t;i--){
                // k++;
                ans[i][l]=v[k];
                k++;
            }
            l++;
        }
        
        
        
        
        
        return ans;
    }
};