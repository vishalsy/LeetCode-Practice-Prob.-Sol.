class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int>m;
        for(int i=0;i<s.size();i++)
        {
            m[s[i]]++;
        }
        int ct=0;
        int t=0;
        int j=0;
        for(auto i:m){
            if(i.second%2==0) ct+=i.second;
            else{ct+=i.second-1;
                 j++;
                }
            
        }
        if(j>0) ct+=1;
        return ct;
    }
};