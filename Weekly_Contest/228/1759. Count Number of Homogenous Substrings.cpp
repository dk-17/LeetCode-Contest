class Solution {
public:
    int countHomogenous(string s) {
        long long int count=0;
        int ans=0;
        int mod=1000000007;
        if(s.length()==0)
            return 0;
        if(s.length()==1)
            return 1;
        for(int i=0;i<s.length()-1;i++){
            count++;
            if(s[i]!=s[i+1]){
                ans=(ans+(count*(count+1))/2)%mod;
                count=0;
            }
            // cout<<"count= "<<count<<endl;
            // cout<<"ans= "<<ans<<endl;
        }
        if(s[s.length()-1]==s[s.length()-2]){
            count++;
            ans=(ans+(count*(count+1))/2)%mod;
        }
        else
            ans++;
        return ans;
        
    }
};
