//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool bfs(int k, vector<int>adj[],vector<int>&vis){
        // vis[k]=1;
        queue<pair<int,int>>q;
        q.push({k,-1});
        while(!q.empty()){
            int a=q.front().first;
            int b=q.front().second;
            vis[a]=1;
            q.pop();
            
            for(auto x:adj[a]){
                if(vis[x]==0 && x!=b){
                    q.push({x,a});
                }
                else if(vis[x]==1 && x!=b){
                    return true;
                }
            }
        }
        return  false;
    }
    
    
    
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                if( bfs(i,adj,vis)) return true;
            }
           
        }
          return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends