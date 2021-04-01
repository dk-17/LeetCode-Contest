class Solution {
public:
    void DFS(int i,int j ,vector<vector<int>>& grid,vector<vector<bool>>& visited){
       
        if( i >=0 &&  i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] && !visited[i][j]){
        visited[i][j] = true;
        DFS( i+1,j,grid,visited);
        DFS( i-1,j,grid,visited);
        DFS( i,j+1,grid,visited);
        DFS( i,j-1,grid,visited);
        }
        return;
    }
    
    int Count_islands(vector<vector<int>> & grid){
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        int islands = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] && !visited[i][j]){
                    islands++;
                    DFS(i,j,grid,visited);
                }
            }
        }
        return islands;
    }
    
    int minDays(vector<vector<int>>& grid) {
        int islands = Count_islands(grid);
        if(islands > 1 || islands == 0) return 0;
        // looking for 1;
      
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j]){
                    grid[i][j] = 0;
                    islands = Count_islands(grid);
                    if(islands >1 || islands == 0) return 1;
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
        
        
    }
};
