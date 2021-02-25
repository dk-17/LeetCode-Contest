
class Solution {
public:
    bool isNiceString(string & s,int i,int j){
        unordered_map<char,int> lower;
        unordered_map<char,int> upper;
        
        for(int k=i;k<=j;k++){
            if(s[k]>='A' && s[k]<='Z')
                upper[s[k]]++;
            if(s[k]>='a' && s[k]<='z')
                lower[s[k]]++;
           
        }
        
        
        for(int k=i;k<=j;k++){
           
            if(isupper(s[k]) && lower[s[k]+32]==0){
               
                return false;
            }
            if(islower(s[k]) && upper[s[k]-32]==0){
                return false;
            }
        }
        return true;
    }
    
    
    
    
    string longestNiceSubstring(string s) {
        string ans="";
        int max_len=0;
      
        for(int i=0;i<s.length();i++){
            
            for(int j=i;j<s.length();j++){
                if(isNiceString(s,i,j)){
                 
                    if(j-i+1>ans.length())
                        ans=s.substr(i,j-i+1);
                }
            }
        }
        return ans;
        
    }
};
