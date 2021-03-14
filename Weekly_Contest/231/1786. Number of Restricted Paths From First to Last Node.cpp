class Solution {
public:
    int mod = 1e9+7;
    vector<int> dp;
    int DFS(int start,vector<vector<pair<int,int>>> & adj_list, int end, vector<int>& min_distance){
        //base case;
        if(start == end) return 1;
        
        if(dp[start] != -1) return dp[start];
        
        int ans = 0;
        for(int i = 0 ; i < adj_list[start].size(); i++){
            int x = adj_list[start][i].second;
           
            if(min_distance[start] > min_distance[x])
                ans =(ans+ DFS(x,adj_list,end,min_distance))%mod;
              
        }
      
         return dp[start] = ans % mod;
        
        
    }
    
    
    
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        dp.resize(n+1,-1);
        vector<int> parent(n+1,-1);
        vector<int> min_distance(n+1,INT_MAX);
        
        vector<vector<pair<int,int>> > adj_list(n+1);
        for(int i = 0; i<edges.size(); i++){
            int x = edges[i][0];
            int y = edges[i][1];
            int w = edges[i][2];
            
            adj_list[x].push_back({w,y});
            adj_list[y].push_back({w,x});
        }
      
        priority_queue<pair<int,int> ,vector<pair<int,int>> ,greater<pair<int,int>> > pq;
        min_distance[n] = 0;
        pq.push({0,n});
        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();
            int x = temp.second;
            int weight = temp.first;
            
            for(int i = 0; i < adj_list[x].size(); i++){
                int y = adj_list[x][i].second;
                int w = adj_list[x][i].first;
                
                if(min_distance[y] > weight + w){
                    min_distance[y] = weight + w;
                    pq.push({weight + w , y});
                }
             }
        }
       
        
        return DFS(1,adj_list,n,min_distance);
        
    }
};
