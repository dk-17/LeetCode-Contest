class Solution {
public:
    vector<int> parent,rank;
    
    int find(int x){
        if(parent[x] == x) return x;
        return parent[x]= find(parent[x]);
    }
    
    void _union(int x ,int y){
        int x_root = find(x);
        int y_root = find(y);
        
        if(x_root != y_root){
            rank[x_root] < rank[y_root]? parent[x_root] = y_root : parent[y_root] = x_root;
            if(rank[x_root] == rank[y_root]){
                rank[x_root]++;
            }
        }
        return;
    }
    
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        parent.resize(n,0);
        rank.resize(n,1);
        for(int i = 0; i < n;i++)
            parent[i] = i;
        vector<pair<int,pair<int,int>> >edges;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                
                    int x1 = points[i][0];
                    int y1 = points[i][1];
                    int x2 = points[j][0];
                    int y2 = points[j][1];
                    int cost = abs(x1 - x2) + abs(y1 - y2);
                    
                    edges.push_back({cost,{i,j}});
                
            }
        }
        sort(edges.begin(),edges.end());
        // cout<<"edges.sizse()= "<<edges.size()<<endl;
        // for(int i = 0; i < edges.size(); i++){
        //     cout<<edges[i].first<<" "<<edges[i].second.first<<" "<<edges[i].second.second<<" ";
        //     cout<<endl;
        // }
        
        int ans = 0;
        int e = 0;
        int  i = 0;
        while(e < n - 1 && i < edges.size() ){
            int x = edges[i].second.first;
            int y = edges[i].second.second;
            
            int x_root = find(x);
            int y_root = find(y);
            
            if(x_root != y_root){
                e++;
                ans += edges[i].first;
                _union(x,y);
                
            }
            i++;
            
        }
        
        return ans;   
    }
};
