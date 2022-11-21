class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>>st;
        int i=0;
        int n=s.size();
        
        while(i<n){
            if(s[i]=='(') st.push({'(',i});
            else if(s[i]==')' && st.size()!=0 && st.top().first=='(')
            {
               st.pop();
            }else if(s[i]==')'){
                st.push({')',i});
            }
            i++;
        }
        // cout<<st.size();
        while(st.size()!=0){
           s[st.top().second]='1';
            st.pop();
        }
        
        string ans;
        
        for(int i=0;i<s.size();i++){
            if(s[i]!='1') ans+=s[i];
        }
        for(auto i:ans){
            cout<<i<<" ";
        }
   
        return ans;
        
    }
};