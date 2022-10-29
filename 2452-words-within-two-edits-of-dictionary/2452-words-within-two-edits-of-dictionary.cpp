class Solution {
public:
    vector<string> twoEditWords(vector<string>& q, vector<string>& d) {
        
        vector<string>ans;
        for(int i=0;i<q.size();i++){
           string s=q[i];
            int n=d.size();
            int x=0;
                while(x<n){
                 int ct=0;
                    string a=d[x];
                    for(int j=0;j<s.size();j++)
                    {
                        if(s[j]==a[j]) ct++;
                    }
                    cout<<ct;
                    if(s.size()-ct<=2){
                        ans.push_back(s);
                        break;
                    }
                    x++;
             }
        }
        
        return ans;
        
    }
};