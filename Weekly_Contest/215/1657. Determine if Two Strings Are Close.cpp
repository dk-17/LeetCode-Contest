class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> f1(26,0),f2(26,0);
        int n=word1.size();
        int m=word2.size();
        if(n!=m)
            return false;
        for(int i=0;i<n;i++){
            f1[word1[i]-'a']++;
            f2[word2[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(f1[i] > 0 != f2[i] > 0)
                return false;
            
        }
        sort(f1.begin(),f1.end());
        sort(f2.begin(),f2.end());
        for(int i=0;i<26;i++)
        {
           
            if(f1[i]!=f2[i])
                return false;
        }
        return true;
    }
};
