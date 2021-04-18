class Solution {
public:
    bool checkIfPangram(string s) {
        vector<bool>v(26,false);
        for(int i = 0; i<s.length();i++){
            v[s[i]-'a']=true;
        }
        for(int i = 0; i< v.size();i++){
            if(v[i]==false) return false;
        }
        return true;
    }
};
