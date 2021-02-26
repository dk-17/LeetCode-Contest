class Solution {
public:
    vector<int> minOperations(string s) {
        vector<int>ans;
        vector<int> index;
        for(int i=0;i<(int)s.length();i++){
            if(s[i]=='1')
                index.push_back(i);
        }
        
        for(int i=0;i<s.length();i++){
            int add=0;
            for(int j=0;j<index.size();j++){
                add+=abs(index[j]-i);
            }
            ans.push_back(add);
        }
        return ans;
        
    }
};
