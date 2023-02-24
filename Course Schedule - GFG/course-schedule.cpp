//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int numCourses, int m, vector<vector<int>> pre) 
    {
         vector<vector<int>>adj(numCourses);
        vector<int>ind(numCourses,0);

        for(int i=0;i<pre.size();i++){
            int a=pre[i][0];
            int b=pre[i][1];
            adj[b].push_back(a);
        }

        for(int i=0;i<numCourses;i++){
            for(auto x:adj[i]){
                ind[x]++;
            }
        }
        // for(auto x:ind){
        //     cout<<x<<" ";
        // }
        queue<int>q;
        vector<int>ans;
        for(int i=0;i<ind.size();i++)
        {
            if(ind[i]==0){
                // cout<<i<<" ";
                 q.push(i);
            }
        }
        // cout  <<q.size();
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            // cout<<node<<" ";

            for(auto x:adj[node]){
                ind[x]--;
                if(ind[x]==0) q.push(x);
            }

        }
        // for(auto x:ans) cout<<x<<" ";
        // cout<<numCourses<<" "<<ans.size();
        if(ans.size()==numCourses) return ans;
       
    return {};
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends