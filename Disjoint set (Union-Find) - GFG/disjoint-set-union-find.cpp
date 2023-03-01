//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int find(int a[],int x);
void unionSet(int a[],int x ,int z);
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n+1];
		for(int i=1;i<=n;i++)
			a[i]=i;
		int k;
		cin>>k;
		for(int i=0;i<k;i++){
			string s;
			cin>>s;
			if(s=="UNION"){
				int z,x;
				cin>>x>>z;
				unionSet(a,x,z);
			}
			else{
				int x;
				cin>>x;
				int parent=find(a,x);
				cout<<parent<<" ";
			}
		}
		cout<<endl;
	}
}
// } Driver Code Ends


// vector<int>par(n+1,0).rank(n+1,0);
// for(int i=1;i<n+1;i++){
//     par[i]=i;
// }

int find(int A[],int X)
{
      if(A[X]==X) return X;
      return find(A,A[X]);
}




void unionSet(int A[],int X,int Z)
{     
          int x=find(A,X);
          int y=find(A,Z);
          
          if(x==y) return;
          else A[x]=y;   
	
}