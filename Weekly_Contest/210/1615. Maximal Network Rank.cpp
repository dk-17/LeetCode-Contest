class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        if(roads.size()==0) return 0;
        unordered_map<int,int> count_nodes;//key->nodes,value->frequency;
        vector<int> adj_list[n];
        
        for(int i=0;i<roads.size();i++){
            int a = roads[i][0];
            int b = roads[i][1];
            
            count_nodes[a]++;
            count_nodes[b]++;
           
            
            adj_list[a].push_back(b);
            adj_list[b].push_back(a);
           
            
            
        }
       
       
        vector<pair<int,int>> v;
        for(auto it = count_nodes.begin();it!=count_nodes.end();it++){
            v.push_back({it->second,it->first});
        }
        
        // v stored the frequency with the nodes;
        sort(v.begin(),v.end(),greater<pair<int,int>>());
        int result=0,ans=0;
        for(int i=0;i<v.size()-1;i++){
          for(int j=i+1;j<v.size();j++){
       
            ans=v[i].first+v[j].first;
       
           for(int k=0;k<adj_list[v[i].second].size();k++) {
            
            if(adj_list[v[i].second][k] == v[j].second){ 
                ans--;
                break;
              }
           }
              
            result=max(result,ans);
        }
              
    }
        return result;     
        
    }
};
