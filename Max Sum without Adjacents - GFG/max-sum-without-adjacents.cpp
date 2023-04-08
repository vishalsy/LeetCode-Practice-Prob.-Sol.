//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
     
    int maxsum(int *arr,int i,vector<int>&dp){
        if(i<0){
            return 0;
        }
        if(dp[i]!=-1 ) return dp[i];
            
            int pick=arr[i]+maxsum(arr,i-2,dp);
            int notpick=maxsum(arr,i-1,dp);
            
            return dp[i]=max(pick,notpick);
        
    }
    
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	       vector<int>dp(n,-1);
           return  maxsum(arr,n-1,dp);
 	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends