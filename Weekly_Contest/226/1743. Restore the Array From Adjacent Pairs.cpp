class Solution {
public:
    
    void dfs(map<int,vector<int>>& adj_list,set<int>& visited,int node,vector<int>& ans){
        if(visited.find(node)!=visited.end())
            return;
        visited.insert(node);
        ans.push_back(node);
        for(int i=0;i<adj_list[node].size();i++)
            dfs(adj_list,visited,adj_list[node][i],ans);
        
        
    }
    
    
    
    
    vector<int> restoreArray(vector<vector<int>>& a) {
        map<int,vector<int>> adj_list;
        for(int i=0;i<a.size();i++){
            adj_list[a[i][0]].push_back(a[i][1]);
            adj_list[a[i][1]].push_back(a[i][0]);
            
        }
        
        int head;
        for(auto i=adj_list.begin();i!=adj_list.end();i++){
            if(i->second.size()==1)
                head=i->first;
        }
        set<int> visited;
        vector<int> ans;
        dfs(adj_list,visited,head,ans);
        return ans;
        
    }
};
