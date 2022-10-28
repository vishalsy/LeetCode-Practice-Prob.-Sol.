class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int,int>m;
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
            int val=target-nums[i];
            if(m.find(val)!=m.end())
            {
                ans.push_back(i);
                ans.push_back(m[val]);
                return ans;
                
            }
            
            m[nums[i]]=i;
            
        }
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
    }
};