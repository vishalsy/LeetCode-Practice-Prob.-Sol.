class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int l,r;
        l=0;r=matrix[0].size()-1;
        int t,d;
        t=0;d=matrix.size()-1;
        
        vector<int>ans;
        // cout<<r<<" ";
        while(l<=r && t<=d ){
            
            for(int i=l;i<=r;i++){
                ans.push_back(matrix[t][i]);
            }
            t++;
            cout<<t<<d;
            for(int i=t;i<=d;i++){
                ans.push_back(matrix[i][r]);
            }
            r--;
            if(l>r || t>d) break;
            
            for(int i=r;i>=l;i--){
                ans.push_back(matrix[d][i]);
            }
            d--;
            
            for(int i=d;i>=t;i--){
                ans.push_back(matrix[i][l]);
            }
            l++;
            // if(l>r || t>d) break;
            // cout<<l<<" "<<r<<" "<<t<<" "<<d<<endl;
            
        }
        return ans;
    }
};