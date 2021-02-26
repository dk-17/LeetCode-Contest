
class Solution {
public:
    
    int Lookup(string & s,int start,int end,vector<vector<int>>& dp){
        if(dp[start][end]>=0)
            return dp[start][end];
        if(start==end)
            return dp[start][end]=1;
        if(end-start==1)
          return    dp[start][end]=(s[start]==s[end]);
        
        return dp[start][end]=(s[start]==s[end] && Lookup(s,start+1,end-1,dp) );
        
    }
    
    
    
    
    bool checkPartitioning(string s) {
        vector<vector<int>> dp;
        dp.resize(s.length()+1,vector<int>(s.length()+1,-1));
        for(int len=1;len<=s.length();len++){
            for(int i=0;i<=s.length()-len;i++)
                Lookup(s,i,i+len-1,dp);
        }
        
        
        for(int i=1;i<s.length()-1;i++){
            for(int j=i;j<s.length()-1;j++)
                if(dp[0][i-1] && dp[i][j] && dp[j+1][s.length()-1]){
                    return true;
                }
        }
        return false;
    }
};
