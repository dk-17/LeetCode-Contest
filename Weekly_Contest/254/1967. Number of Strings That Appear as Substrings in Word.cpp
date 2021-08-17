class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        unordered_map<string,int> umap;
        for(int i = 0; i < word.size(); i++){
            string str  = "";
            for(int j = i; j < word.size(); j++){
                str+=word[j];
                umap[str]++;
            }
        }
        
        int ans = 0;
        for(int i =0; i< patterns.size(); i++){
            string s = patterns[i];
            if(umap.find(s) != umap.end()) ans++;
        }
        return ans;
        
    }
};
