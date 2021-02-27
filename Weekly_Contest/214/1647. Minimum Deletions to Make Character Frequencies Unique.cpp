class Solution {
public:
    int minDeletions(string s) {
        vector<int> v(26,0);
        for(int i=0;i<s.length();i++){
            v[s[i]-'a']++;
        }
        sort(v.begin(),v.end(),greater<int>());
        
        int cutoff=v[0];
        int ans=0;
        for(int i=0;i<26;i++){
            if(cutoff<0 && v[i]>0)
            {
                
                ans+=v[i];
            
            }
           else if(v[i]==cutoff){
                cutoff--;
            }
            else if(v[i]<cutoff)
                cutoff=v[i]-1;
            else if(v[i]>cutoff&& cutoff>=0){
                ans+=v[i]-cutoff;
            
                cutoff--;
            }
        }
        return ans;
    }
};
