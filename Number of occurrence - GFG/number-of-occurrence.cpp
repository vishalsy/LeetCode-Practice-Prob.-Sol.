//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	     
         int start=0,end=n-1;
    int res=-1;
    bool flag=true;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        
        if(arr[mid]==x){
            res=mid;
            end=mid-1;
      
        }
        else if(arr[mid]<x){
            start=mid+1;
        }else{
            end=mid-1;
        }
    }
    //  cout<<res<<" ";
     vector<int>ans(2,-1);
      ans[0]=res;
      start=0;
      end=n-1;
        while(start<=end)
        {
        int mid=start+(end-start)/2;
        
        if(arr[mid]==x){
            res=mid;
            start=mid+1;
      
        }
        else if(arr[mid]<x){
            start=mid+1;
        }else{
            end=mid-1;
        }
        }
    // cout<<res<<endl;
     ans[1]=res;
    //  cout<<ans[0]<<" "<<ans[1]<<endl;
     if (ans[0]==-1) return 0;
     else return ans[1]-ans[0]+1;
       return 7;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends