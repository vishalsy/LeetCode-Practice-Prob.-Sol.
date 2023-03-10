//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool Search(int N, vector<int>& nums, int target) {
         int n=nums.size();
        int start=0;
        int end=n-1;

        while(start<=end){
            int mid=start+(end-start)/2;

            if(nums[mid]==target){
                return 1;
            }

            if(nums[mid]==nums[end] && nums[mid]==nums[start]){
                start++;
                end--;
            }else if(nums[start]<=nums[mid]){
                if(nums[start]<=target && target<=nums[mid]) end=mid-1;
                else start=mid+1;
            }
            else{
                if(nums[mid]<=target && target<=nums[end]) start=mid+1;
                else end=mid-1;
            }
            // cout<<mid<<" ";
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int key;
        cin >> key;

        Solution obj;
        cout << obj.Search(n, a, key) << "\n";
    }
    return 0;
}
// } Driver Code Ends