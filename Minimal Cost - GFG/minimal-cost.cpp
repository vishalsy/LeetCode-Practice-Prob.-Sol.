//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
     int find(vector<int>& height, int i, int k,vector<int>&dp){
         if(i==0){
             return 0;
         }
         if(dp[i]!=-1) return dp[i];
         int minima=INT_MAX;
         
         for(int j=1;j<=k;j++){
             if(i-j>=0){
                 minima=min(minima,find(height,i-j,k,dp)+abs(height[i]-height[i-j]));
             }
         }
        
         return  dp[i]=minima;
     }

  
    int minimizeCost(vector<int>& height, int n, int k) {
        vector<int>dp(n,-1);
        //   return find(height,n-1,k,dp);
        dp[0]=0;
        for(int i=1;i<n;i++){
            int minima=INT_MAX;
            
            for(int j=1;j<=k;j++){
                if(i-j>=0) minima=min(minima,dp[i-j]+abs(height[i]-height[i-j]));
            }
            dp[i]=minima;
        }
        return dp[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends