class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int>m;
        
        for(int i=0;i<s.size();i++){
            m[s[i]]=i;
        }
        
        vector<int>ans;
        int ct=1;
        int i=0;
         while(i<s.size()){
             int k=m[s[i]];
             for(int j=i+1;j<k;j++){
                 if(k>m[s[j]]){
                     continue;
                 }else{
                     k=m[s[j]];
                 }
             }
             ans.push_back(k+1);
             i=k+1;
         }
        int sum=ans[0];
        for(int i=1;i<ans.size();i++){
            ans[i]=ans[i]-sum;
            sum+=ans[i];
        }
        
        return ans;
    }
};