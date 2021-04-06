class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<int>> height(n,vector<int>(m,INT_MAX));
        vector<vector<int>> dir={{-1,0},{1,0},{0,1},{0,-1}};
        queue<pair<int,pair<int,int>>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0 ; j < m; j++){
                if(isWater[i][j]){
                   q.push({0,{i,j}});
                    height[i][j] = 0;
                }
                
            }
        }
   
        while(!q.empty()){
            int h = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();
          
            for(int k = 0; k < 4; k++){
                int i = x + dir[k][0];
                int j = y + dir[k][1];
                
                if(i < 0 || j < 0 || i >= n || j >= m  ) continue;
                if(height[i][j] == INT_MAX){
                    height[i][j] = h + 1;
                    q.push({h+1,{i,j}});
                }
            }
        }
        return height;
        
    }
};
