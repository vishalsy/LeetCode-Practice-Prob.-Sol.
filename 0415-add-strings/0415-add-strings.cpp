class Solution {
public:
    string addStrings(string num1, string num2) {
        int i=num1.size()-1;
      int j=num2.size()-1;
      int sum=0;
        string s;
        while(i>=0 && j>=0){
            sum+=(num1[i]-'0')+(num2[j]-'0');
            s.push_back(char(sum%10+'0'));
            sum/=10;
            i--;
            j--;
        }
        
        while(i>=0 ){
            sum+=(num1[i]-'0');
            s.push_back(char(sum%10+'0'));
            sum/=10;
            i--;
        }
         while(j>=0 ){
            sum+=(num2[j]-'0');
            s.push_back(char(sum%10+'0'));
            sum/=10;
             j--;
        }
        
        if(sum>0){
            s.push_back(char(sum%10+'0'));
        }
        
       reverse(s.begin(),s.end());
        
        // return "";
        return s;
    }
};