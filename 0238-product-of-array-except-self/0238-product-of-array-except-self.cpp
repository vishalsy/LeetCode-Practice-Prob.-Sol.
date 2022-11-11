class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>ans;
        int k=1;
        int sum=1;
        int ct=0;
        for(auto i:nums){
            if(i!=0){ 
               k*=i;
                ct++;
            }
            
            sum*=i;
        }
        for(auto i:nums){
            if(i==0 && nums.size()-ct==1)
              ans.push_back(k);
            else if(i==0 && nums.size()-ct==0)
                ans.push_back(0);
            else if(nums.size()-ct>1) ans.push_back(0);
            else ans.push_back(sum/i);
        }
        return ans;
    }
};