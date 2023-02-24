//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<vector<pair<int,int>>>adj(N);
          
          for(int i=0;i<M;i++){
              int a=edges[i][0];
              int b=edges[i][1];
              int c=edges[i][2];
              adj[a].push_back({b,c});
          }
          
          vector<int>dist(N,1e5);
          priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
          pq.push({0,0});
          dist[0]=0;
          
          while(!pq.empty())
          {
              int node=pq.top().second;
              int d=pq.top().first;
              pq.pop();
              
              for(auto i:adj[node]){
                  int child=i.first;
                  int x=i.second;
                  if(dist[child]>=d+x){
                      dist[child]=d+x;
                      pq.push({d+x,child});
                  }
              }

          }


          for(int i=0;i<N;i++)
          {
              if(dist[i]==1e5) dist[i]=-1;
          }
          
          return dist;
          
          
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends