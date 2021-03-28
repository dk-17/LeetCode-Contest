class Solution {
public:
 
    int numDifferentIntegers(string word) {
        unordered_map<string ,int> umap;
        string str = "";
        string s = "";
        for(int i = 0; i < word.length(); i++){
            if(isdigit(word[i])){
               if(str.length()==1 && str[0]=='0') str = "";
                str+=word[i];
            }
            else{
                if(str.length()>0 )
                umap[str]++;
                str = "";
            }
        }
     
        if(str.length()!=0) umap[str]++;
        return umap.size();
        
    }
};
