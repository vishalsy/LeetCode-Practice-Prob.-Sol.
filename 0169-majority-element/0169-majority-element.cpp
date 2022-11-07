class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int k,ct=0;
        for(int i=0;i<nums.size();i++){
            if(ct){
                ct+=(nums[i]==k ? 1 : -1);
            }else
            {
                k=nums[i];
                ct=1;
            }
        }
        return k;
    }
};