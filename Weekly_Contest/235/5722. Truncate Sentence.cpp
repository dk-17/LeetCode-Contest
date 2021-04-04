class Solution {
public:
    string truncateSentence(string s, int k) {
        int  count = 0;
        string ans = "";
        for(int i = 0; i< s.length(); i++){
            if(isspace(s[i])) count++;
            if(count == k) break;
            ans+=s[i];
        }
        return ans;
        
    }
};
