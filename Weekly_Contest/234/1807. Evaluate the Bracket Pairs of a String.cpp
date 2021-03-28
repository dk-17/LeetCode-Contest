class Solution {
public:
     unordered_map<string,string> umap;
    string word(string & s,int & index){
        string ans = "";
        while(s[index] !=')'){
            if(s[index] == '('){
                index++;
                ans += word(s,index);
                
            }
            else
                ans +=s[index++];
        }
        if(s[index] == ')')index++;
        if(umap.find(ans)== umap.end())
            return "?";
        return umap[ans];
        
        
    }
    
    
    
    
    string evaluate(string s, vector<vector<string>>& k) {
       umap.clear();
        for(int i = 0; i< k.size(); i++){
            umap[k[i][0]] = k[i][1];
        }
        
        string ans = "";
        int i = 0;
        while(i < s.length()){
            if(s[i] == '('){
                i++;
                ans += word(s,i);
                
            }
            else
                ans +=s[i++];
        }
        return ans;
        
    }
};
