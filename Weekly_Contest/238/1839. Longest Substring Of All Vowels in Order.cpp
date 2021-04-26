class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int ans = 0;
        int max_l = 0;
        string s = "aeiou";
        int k = 0;
        int i = 0,j = 0;
        while(j < word.size()){
          
            if(word[j] == s[k]){
                j++;
                continue;
            }
            if(word[j]!=s[k]){
                k++;
                if( k >= s.length()){
                ans = max(ans,j-i);
            }
                if(word[j]!=s[k]){
                    k = 0;
                    while(j < word.length()&& word[j]!=s[k])j++;
                    i = j;
                }
                
            }
            if( k >= s.length()){
                ans = max(ans,j-i);
            }
        }
      
        if( k >= s.length()-1){
                ans = max(ans,j-i);
            }
        return ans;
        
    }
};
