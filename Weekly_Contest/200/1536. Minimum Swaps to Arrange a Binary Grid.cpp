class Solution {
public:
    int ZerosAtEnd(vector<int>& row){
        int count = 0;
        int n = row.size();
        for(int i = n-1; i >= 0; i--){
            if(row[i]!=0) return count;
            count++;
        }
        return count;
    }
    
    vector<int> gridTovec(vector<vector<int>> & grid){
        int n = grid.size();
        vector<int> ans;
        for(int i = 0; i < n; i++){
            ans.push_back(ZerosAtEnd(grid[i]));
        }
        return ans;
    }
    
    int Solve(vector<int>& v){
        int n = v.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(v[i] < (n-i-1)){
                int j = i;
                while(j < n   && v[j] < (n-i -1)) j++;
                
                 if(j == n) return -1;
                
                while(j > i){
                    swap(v[j],v[j-1]);
                    ans++;
                    j--;
                }
                
                
            }
        }
        
        return ans;
        
        
    }
    
    int minSwaps(vector<vector<int>>& grid) {
        vector<int> v = gridTovec(grid);
       
        return Solve(v);
    }
};
