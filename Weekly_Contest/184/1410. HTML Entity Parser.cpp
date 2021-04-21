class Solution {
public:
    string entityParser(string text) {
        unordered_map<string,string> umap;
        umap["&quot;"] ="\"";
        umap["&apos;"] = "\'" ;
        umap["&amp;"] = "&";
        umap["&gt;"] = ">";
        umap["&lt;"] = "<";
        umap["&frasl;"] = "/";
       int i = 0;
        int j = 0;
        string ans = "";
        string word = "";
        
        while(j < text.length()){
           if(text[j]=='&'){
               i = j;
               while(j < text.length()&& text[j]!=';'){
                 j++;
                   if(text[j]=='&'){
                       i= j;
                       ans+=text[j];
                   }
               } 
               word = text.substr(i,j-i+1);
               if(umap.find(word)!=umap.end())
               ans +=umap[word];
               else
                   ans +=word;
               j++;
           }
           else
            ans += text[j++];
          
            
        }
    
        return ans;
        
    }
};
