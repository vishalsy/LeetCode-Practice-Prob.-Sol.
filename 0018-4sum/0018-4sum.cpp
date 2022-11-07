class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;
            long long int t=target-nums[i];
            for(int x=i+1;x<n;x++)
            {
                if(x>i+1 && nums[x]==nums[x-1]) continue;
                int k=n-1;
                int j=x+1;
                long long int s=t-nums[x];
                while(j<k)
                {
                       if(s==(nums[k]+nums[j])){
                             ans.push_back({nums[i],nums[x],nums[j],nums[k]});
                             while(j<k and nums[j]==nums[j+1]) j++;
                             while(k>j and nums[k]==nums[k-1]) k--;
                             j++;
                             k--;
                      }else if(nums[j]+nums[k]>s){
                             k--;
                      }else{
                             j++;
                      }
               }
           }
       }
        
        return ans;        
    }
};