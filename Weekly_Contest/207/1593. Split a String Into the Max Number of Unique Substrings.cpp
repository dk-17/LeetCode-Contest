class Solution {
public:
    unordered_map<string,int> umap;
    int ans;
    void DFS(int index,string & s){
        if(index>=s.length()){
            
            ans = max(ans,(int)umap.size());
        
        }
        string word = "";
        
        for(int i=index;i<s.length();i++){
            word+=s[i];
            if(umap[word]) continue;
            umap[word]++;
            DFS(i+1,s);
            umap.erase(word);
            
        }
        return;
    }
    
    int maxUniqueSplit(string s) {
        umap.clear();
        ans=0;
        DFS(0,s);
        return ans;
        
    }
};
