class Solution {
public:
    vector<vector<int>> position;
    unordered_set<int> ans;//set tc -->o(log n) while unordered_set tc is ----> o(1);
     void CheckHappines(int x, int y, int u, int v){
         if(position[x][u] < position[x][y] && position[u][x] < position[u][v]){
             ans.insert(x);
             ans.insert(u);
           
             
         }
     }
    
    
    
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        position.resize(n,vector<int>(n,0));
        ans.clear();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n-1; j++){
                position[i][preferences[i][j]]=j+1;
            }
        }
        // for(int i = 0; i < n; i++){
        //     for(int j =0; j< n;j++)
        //         cout<<position[i][j]<<" ";
        //     cout<<endl;
        // }
        
        for(int i = 0; i < pairs.size()-1 ; i++){
            for(int j = i+1; j < pairs.size(); j++){
                int x = pairs[i][0];
                int y = pairs[i][1];
                int u = pairs[j][0];
                int v = pairs[j][1];
                
                CheckHappines(x,y,u,v);
                CheckHappines(x,y,v,u);
                CheckHappines(y,x,u,v);
                CheckHappines(y,x,v,u);
                
            }
        }
        
        
        return ans.size();
        
        
        
        
        
    }
};
