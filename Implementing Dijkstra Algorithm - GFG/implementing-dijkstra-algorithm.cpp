//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
     // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        q.push({0,S});
        vector<int>dis(V);
        for(int i=0;i<V;i++){
            dis[i]=1e9;
        }
        dis[S]=0;
        while(!q.empty()){
          int node=q.top().second;
          int d=q.top().first;
          q.pop();
          for(auto x:adj[node]){
              int a=x[0];
              int b=x[1];
            if(d+b<dis[a]){
                dis[a]=b+d;
                q.push({dis[a],a});
            }
          }
        }
        return dis;
        // vector<int> distTo(V, INT_MAX);

        // Source initialised with dist=0.
        // distTo[S] = 0;
        // pq.push({0, S});

        // // Now, pop the minimum distance node first from the min-heap
        // // and traverse for all its adjacent nodes.
        // while (!pq.empty())
        // {
        //     int node = pq.top().second;
        //     int dis = pq.top().first;
        //     pq.pop();

        //     // Check for all adjacent nodes of the popped out
        //     // element whether the prev dist is larger than current or not.
        //     for (auto it : adj[node])
        //     {
        //         int v = it[0];
        //         int w = it[1];
        //         if (dis + w < distTo[v])
        //         {
        //             distTo[v] = dis + w;
    
        //             // If current distance is smaller,
        //             // push it into the queue.
        //             pq.push({dis + w, v});
        //         }
        //     }
        // }
        // // Return the list containing shortest distances
        // // from source to all the nodes.
        // return distTo;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends