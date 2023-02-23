//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int node ,vector<int>&vis, vector<vector<int>> &v){
        vis[node]=1;
        for(auto i:v[node]){
            
            if(vis[i]==0 ){
                dfs(i,vis,v);
            }
        }
    }
  
    int numProvinces(vector<vector<int>> adj, int V) {
        int ct=0;
        vector<vector<int>>v(V);
        vector<int>vis(V,0);
           for(int i=0;i<adj.size();i++){
            for(int j=0;j<adj[i].size();j++){
            
                if(adj[i][j]==1 && i!=j){
                    v[i].push_back(j);
                    v[j].push_back(i);
                }
            }
        }
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,v);
                ct++;
            }
            
        }
        return ct;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends