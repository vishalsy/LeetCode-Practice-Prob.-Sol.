class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        vector<vector<int>>ans;
        if(in.size()==0) return ans;
        sort(in.begin(),in.end());
            
        vector<int>v=in[0];
        
        for(auto i:in){
            if(i[0]<=v[1]){
                v[1]=max(v[1],i[1]);
            }else{
                ans.push_back(v);
                v=i;
            }
        }
        ans.push_back(v);
        
        
        return ans;
    }
};