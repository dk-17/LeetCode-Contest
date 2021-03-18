class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<double> dis(n,0.0);
        vector<vector<pair<int,double>> > adj_list(n);
        for(int i = 0; i < edges.size(); i++){
            int x = edges[i][0];
            int y = edges[i][1];
            double w = succProb[i];
            
            adj_list[x].push_back({y,w});
            adj_list[y].push_back({x,w});
            
        }
        
        dis[start] = 1.0;
        priority_queue<pair<double,int>> pq;
        pq.push({1.0,start});
        int flag = 0;
        while(!pq.empty()){
            
            auto temp = pq.top();
            pq.pop();
            
            int x = temp.second;
           
            double p = temp.first;
            
            for(int i = 0; i < adj_list[x].size(); i++){
                int y = adj_list[x][i].first;
                double _p = adj_list[x][i].second;
           
                if(dis[y] < p * _p){
                    dis[y] = p * _p;
                    pq.push({p * _p,y});
                }
                
              if(y == end) break;
            }
            
            
            
        }
        
        return dis[end];
        
    }
};
