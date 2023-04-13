//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:




    void solve(int num,string s,int i){
        if(i==num){
            cout<<s<<" ";
            // cout<<i<<" ";
            return;
        }
         s+='0';
         solve(num,s,i+1);
         s.pop_back();
         if(s.size()==0 || s[s.size()-1]=='0'){
             s+='1';
             solve(num,s,i+1);
         }
    }






   
    void generateBinaryStrings(int num){
        string s="";
        solve(num,s,0);
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        obj.generateBinaryStrings(n);
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends