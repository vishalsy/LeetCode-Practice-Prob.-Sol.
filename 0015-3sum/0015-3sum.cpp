class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int k=n-1;
            int j=i+1;
            while(j<k){
                if(nums[i]+nums[j]+nums[k]==0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                     while(j<k and nums[j]==nums[j+1]) j++;
                     while(k>j and nums[k]==nums[k-1]) k--;
                    j++;
                    k--;
                }else if( nums[i]+nums[j]+nums[k]>0){
                    k--;
                }else{
                    j++;
                }
            }
        }
        // vector<vector<int>>res;
        // for(auto i:ans){
        //     res.push_back(i);
        // }
       return ans;
        
        
    }
};