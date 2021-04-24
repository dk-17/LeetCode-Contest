class Solution {
public:
    bool isvalid(unordered_map<char,int>& umap){
        if(umap['c'] >= umap['r'] && umap['r'] >= umap['o'] && umap['o']>= umap['a']&& umap['a']>= umap['k']) return true;
        return false;
    }
    int minNumberOfFrogs(string s) {
        unordered_map<char,int> umap;
        int ans = 0;
        int count = 0;
        for(int i = 0; i< s.length();i++){
            umap[s[i]]++;
            if(!isvalid(umap)) return -1;
            if(s[i]=='c') count++;
            if(s[i]=='k') count--;
            ans = max(ans,count);
        }
    return (count == 0)? ans:-1;
    }
};
