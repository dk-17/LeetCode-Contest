class Solution {
public:
    int minFlips(string s) {
        char cur = '0';
        int count = 0;
        for(int i = 0; i < s.length(); i++){
            if(cur != s[i]){
                cur = s[i];
                count++;
             
            }
        }
        if(count == 0) return 0;
        
        return count;
        
        
    }
};
