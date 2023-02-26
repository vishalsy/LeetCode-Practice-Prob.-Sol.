//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>> 
        ,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>q;
    
        int n=heights.size();
        int m=heights[0].size();
        
        q.push({0,{0,0}});
        
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        
        while(!q.empty()){
            
            
            auto x=q.top();
            int diff=x.first;
            int a=x.second.first;
            int b=x.second.second;
            
            q.pop();
            
            if(a==n-1 && b==m-1) return diff;
            
            for(int i=0;i<4;i++){
                int x=dx[i]+a;
                int y=dy[i]+b;
                
                if(x>=0 && y>=0 && x<n && y<m){
                    
                  int newdiff=max(abs(heights[x][y]-heights[a][b]),  diff);
                  
                  if(newdiff<dist[x][y]){
                      
                      dist[x][y]=newdiff;
                      
                      q.push({newdiff,{x,y}});
                  }
                } 
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends