class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        vector<char> v(s.length());
        for(int i = 0; i < s.length(); i++){
            v[indices[i]] = s[i];
        }
        string ans = "";
        for(int i = 0; i < s.length(); i++){
            ans += v[i];
        }
        return ans;
        
        
    }
};
