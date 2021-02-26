class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        
        vector<int> ans;
        int n=grid.size();
        int m= grid[0].size();
        //iteration coloum wise
        for(int i=0;i<m;i++){
            int i1=i,i2;//i1 is repesenting the column and i2 is calculated which column to be consider!
            for(int j=0;j<n;j++){
                i2=i1+grid[j][i1];
                if(i2<0 || i2>=m || grid[j][i1]!=grid[j][i2]){
                    i1=-1;
                    break;
                }
                i1=i2;
            }
            ans.push_back(i1);
        }
        return ans;
        
        
    }
};
