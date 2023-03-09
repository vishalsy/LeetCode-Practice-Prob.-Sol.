//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    int BS(int start,int end ,int *A,int k){
        
        while(start<=end){
              int mid=start+(end-start)/2;

              if(A[mid]==k){
                 return mid;
              }
              else if(A[mid]>k){
                  end=mid-1;
              }else{
                  start=mid+1;
              }
        
        }
        return -1;
    }

    int search(int A[], int l, int h, int key){
          int start=l;
          int end=h;
          int n=h+1;
          int ans;
        //   cout<<l<<" "<<h<<endl;
          
          while(start<=end){
              int mid=start+(end-start)/2;
            //   cout<<mid<<" "<<A[mid]<<endl;
              
              
              int next=(mid+1)%n;
              int pre=(mid+n-1)%n;
              
              if(A[mid]<=A[next] && A[mid]<=A[pre]){
                  ans=mid;
                  break;
              }
              else if(A[mid]<A[end]){
                  end=mid-1;
              }else{
                  start=mid+1;
              }
        
          }
        //   cout<<ans<<endl;
          int ans1=BS(l,ans,A,key);
          int ans2=BS(ans,h,A,key);
        //   cout<<ans1<<" "<<ans2<<endl;
            
          if(ans2==-1 && ans1==-1) return -1;
          else return max(ans1,ans2);
    }
};

//{ Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}
// } Driver Code Ends