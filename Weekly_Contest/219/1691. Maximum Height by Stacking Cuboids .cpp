class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        vector<int> row;
        for(int i=0;i<cuboids.size();i++){
            for(int j=0;j<3;j++){
                row.push_back(cuboids[i][j]);
            }
         sort(row.begin(),row.end(),greater<int>());
            cuboids[i]=row;
            row.clear();
        }
         sort(cuboids.begin(),cuboids.end(),greater<vector<int>> ());
      
        
        
        vector<int> dp(cuboids.size(),0);
        for(int i=0;i<cuboids.size();i++)
            dp[i]=cuboids[i][0];
        for(int i=1;i<cuboids.size();i++){
            
            for(int j=0;j<i;j++){
                if(cuboids[i][0]<=cuboids[j][0]&&cuboids[i][1]<=cuboids[j][1]&&cuboids[i][2]<=cuboids[j][2]){
                    dp[i]=max(dp[i],dp[j]+cuboids[i][0]);
                }
            }
                
         }

        
        
        return *max_element(dp.begin(),dp.end());
    }
};
