class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int k=n-1;
            int j=i+1;
            while(j<k){
                if(nums[i]+nums[j]+nums[k]==0){
                    ans.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }else if(nums[i]+nums[j]+nums[k]>0){
                    k--;
                }else{
                    j++;
                }
            }
        }
        vector<vector<int>>res;
        for(auto i:ans){
            res.push_back(i);
        }
       return res;
        
        
    }
};