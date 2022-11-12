class Solution {
public:
    vector<vector<int>> generateMatrix(int n){
        int l,r,t,d;
        l=0,r=n-1,t=0,d=n-1;
        vector<vector<int>>v(n, vector<int>(n, 1));
        // int k=n;
        // int v[k][k]={};
        int k=0;
        while(l<=r && t<=d){
            
            for(int i=l;i<=r;i++){
                k++;
                v[t][i]=k;
            }
            t++;
            
            for(int i=t;i<=d;i++){
                k++;
                v[i][r]=k;
            }
            r--;
            if(l>r || t>d) break;
            
            for(int i=r;i>=l;i--){
                k++;
                v[d][i]=k;
            }
            d--;
            
            for(int i=d;i>=t;i--){
                k++;
                v[i][l]=k;
            }
            l++;
        }
        return v;
        
    }
};