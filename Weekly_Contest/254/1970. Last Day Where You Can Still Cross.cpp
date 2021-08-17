class Solution {
public:
    bool ans;
    
    void DFS(vector<vector<int>>& grid,int i ,int j){
        //base case
        if(i == grid.size()){
            ans = true;
            return;
        }
        
        if( i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()|| grid[i][j] == 1) return;
        grid[i][j] = 1;
        DFS(grid,i+1,j);
        DFS(grid,i-1,j);
        DFS(grid,i,j+1);
        DFS(grid,i,j-1);
        
        return;
    }
    
    
    bool possible(int index, int r,int c,vector<vector<int>>& cells){
        vector<vector<int>> grid(r,vector<int>(c,0));
      
        for(int i = 0; i<= index; i++){
            int x = cells[i][0]-1;
            int y = cells[i][1]-1;
           
            grid[x][y] = 1;
          
            
        }
        
        ans = false;
        for(int j = 0;j < c; j++){
            if(grid[0][j] == 0){
                ans = false;
                DFS(grid,0,j);
              
                if(ans) break;
            }
        }
        return ans;
        
    }
    
    
    
    
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
       int result = -1;
       int l = 0, r = cells.size()-1;
        while( l <= r){
            int mid = l + ( r - l)/2;
            if(possible(mid,row,col,cells)) {
                result = mid+1;
                l = mid+1;
            }
            else
                r = mid - 1;
        }
        return result;
        
        
    }
};
