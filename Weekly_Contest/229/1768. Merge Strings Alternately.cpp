class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        string ans="";
        int i=0,j=0;
        int k=0;
        while(i<n && j<m){
            if(k%2==0){
                ans+=word1[i++];
                k++;
            }
            else{
                ans+=word2[j++];
                k++;   
            }
        }
        while(i<n)
            ans+=word1[i++];
        while(j<m)
            ans+=word2[j++];
        
        return ans;
        
    }
};
