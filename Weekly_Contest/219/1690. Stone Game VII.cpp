class Solution {
public:
    int solve(vector<int>& stones,vector<vector<int>> & dp,int i,int j ,int sum){
        //base case;
        if(i==j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        dp[i][j]=max(sum-stones[i]-solve(stones,dp,i+1,j,sum-stones[i]),sum-stones[j]-solve(stones,dp,i,j-1,sum-stones[j]));
        return dp[i][j];
    }
    
    
    
    
    
    int stoneGameVII(vector<int>& stones) {
         int n=stones.size();
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=stones[i];
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(stones,dp,0,n-1,sum);
    
    }
};
