//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> graph[]) {
        // int n=graph.length();
         vector<int>in(V,0);
         vector<vector<int>>adj(V);
         for(int i=0;i<V;i++){
              for(auto x:graph[i]){
                adj[x].push_back(i);
              }
         }
            for(int i=0;i<V;i++){
              for(auto x:adj[i]){
                  in[x]++;
              }
            }
              queue<int>q;
              for(int i=0;i<V;i++){
                  if(in[i]==0) q.push(i);
              }
        vector<int>ans;
        

        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto i:adj[node]){
                in[i]--;
                if(in[i]==0) q.push(i);
            }
        }
        sort(ans.begin(),ans.end());

        return ans;
      }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends