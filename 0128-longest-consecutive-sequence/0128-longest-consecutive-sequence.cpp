class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int>m;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        int t=m.begin()->first;
        int ct=0;
        int maxi=0;
        for(auto i:m){
           ans.push_back(i.first); 
        }
        for(auto i:ans){
            cout<<i<<" ";
        }
        
        for(int i=1;i<ans.size();i++){
            if(ans[i]-1==ans[i-1]){
                ct++;
                maxi=max(ct,maxi);
            }
            else ct=0;
        }
        if(nums.size()==0) return 0;
        return maxi+1;
        
    }
};