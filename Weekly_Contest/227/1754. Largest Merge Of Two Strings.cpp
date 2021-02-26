class Solution {
public:
    
       string largestMerge(string word1, string word2) {
     
        string ans="";
        int i=0,j=0;
        while(i<word1.length() && j< word2.length()){
            if(word1[i]>word2[j]){
                ans+=word1[i];
                    i++;
            }
            else if(word1[i]<word2[j]){
                ans+=word2[j];
                j++;
            }
            else {
                int ii=i,jj=j;
                while(ii<word1.length() && jj<word2.length() && word1[ii]==word2[jj]){
                    ii++;jj++;
                }
                
                if(ii==word1.length())
                    ans+=word2[j++];
                else if(jj==word2.length())
                    ans+=word1[i++];
                else if(word1[ii]>word2[jj])
                    ans+=word1[i++];
                else if(word1[ii]<word2[jj])
                    ans+=word2[j++];
               
                }
            }
          
        
        while(i<word1.length()){
            ans+=word1[i];
            i++;
        }
        while(j<word2.length()){
            ans+=word2[j];
            j++;
        }
        return ans;
        
    }
};
