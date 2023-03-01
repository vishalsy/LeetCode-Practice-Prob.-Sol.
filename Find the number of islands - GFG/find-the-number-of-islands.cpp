//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
       int dx[8]={-1,0,1,0,1,-1,1,-1};
       int dy[8]={0,1,0,-1,1,-1,-1,1};
       
    private:   
       void dfs(int x,int y,vector<vector<char>>& grid,vector<vector<int>>& vis,int n,int m){
           vis[x][y]=1;
           
           for(int i=0;i<8;i++){
               int a=dx[i]+x;
               int b=dy[i]+y;
               
               if(a>=0 && b>=0 && a<n && b<m && vis[a][b]==0 && grid[a][b]=='1') dfs(a,b,grid,vis,n,m);
           }
       }
       public:
    
      int numIslands(vector<vector<char>>& grid) {
          int n=grid.size();
          int m=grid[0].size();
          vector<vector<int>>vis(n,vector<int>(m,0));
          int ct=0;
          for(int i=0;i<n;i++){
             for(int j=0;j<m;j++){
                 if(vis[i][j]==0  && grid[i][j]=='1'){
                    //  if(ct==1) break;
                     ct++;
                     dfs(i,j,grid,vis,n,m);
                 }
             }
          }
        //     for(int i=0;i<n;i++){
        //      for(int j=0;j<m;j++){
        //         cout<<vis[i][j]<<" ";
        //      }
        //      cout<<endl;
        //   }
          
          return ct;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends