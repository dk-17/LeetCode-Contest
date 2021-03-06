class Solution {
public:
    string reorderSpaces(string text) {
        int count = 0,words=0;
        stringstream s(text);
        string word;
        while(s >> word)
            words++;
        for(int i = 0 ; i < text.length() ; i++){
            if(isspace(text[i])) count++;
        }
        
        int left = 0;
        
        if(words!=1 && count % (words-1)!=0){
            left = count % words;
        }
        if(words==1)
            left=count;
        
       
        int add = count/((words!=1)? words-1:1);
       
        
        string ans="";
        stringstream st(text);
        word="";
        while(st >> word){
            ans+=word;
            for(int i=0;i<add;i++)
                ans+=" ";
        }
        int n=text.length();
  
        if(ans.length()>text.length())
        ans.erase(text.length(),ans.length()-text.length());
        else{
            while(ans.length()!=text.length())
                ans+=" ";
        }
        return ans;
        
        
        
    }
};
