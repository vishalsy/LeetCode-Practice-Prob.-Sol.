class Solution {
public:
    bool wordPattern(string p, string s) {
        vector<string>v;
        string a;
        for(int i=0; i<s.size() ;i++){
            if(s[i]==' '){
                v.push_back(a);
                // cout<<a<<" ";
                a.clear();
            }
            else{
                a+=s[i];
            }
        }
        v.push_back(a);
        if(v.size()!=p.size()) return false;
      set<string>k;
        
        map<char,string>m;
        
        for(int i=0; i<p.size() ;i++){
             if(m.find(p[i])!=m.end())
             {
                 if(m[p[i]]!=v[i]) return false;
             }
             else{
                 if(k.count(v[i])>0) return false;
                 
                 k.insert(v[i]);
                 m[p[i]]=v[i];
             }
        }
        for(auto i:m){
            cout<<i.first<<" "<<i.second<<endl;
        }
        
        return true;
    }
};