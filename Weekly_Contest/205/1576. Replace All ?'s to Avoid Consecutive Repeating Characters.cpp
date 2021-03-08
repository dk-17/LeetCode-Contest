class Solution {
public:
    string modifyString(string s) {
        int add = 'a';
        for( int i = 0; i < s.length(); i++){
            if(s[i]=='?'){
                for(s[i] = 'a'; s[i] <='c'; s[i]++){
                    if( (i == 0 || s[i-1] != s[i]) && (i == s.length()-1 ||s[i+1] != s[i]))
                       break;//that is satisfy the conditon therefore no need to change the s[i] value through the loop!
                }
            }
        }
        return s;
        
    }
};
