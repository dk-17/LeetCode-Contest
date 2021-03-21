class Solution {
public:
    vector<int> DFS(int index,vector<int> & ans,vector<bool> & visited,vector<vector<int>>& adj_list,string & labels){
        visited[index] = true;
        vector<int> count(26,0);
        count[labels[index]-'a']=1;
        for(int i = 0; i < adj_list[index].size(); i++){
            int x = adj_list[index][i];
            //cout<<"x = "<<x<<endl;
            if(visited[x]) continue;
            vector<int> cnt = DFS(x,ans,visited,adj_list,labels);
            
            for(int j = 0; j < 26; j++){
                count[j]+=cnt[j];   
            }
           
        }
        
        ans[index]+=count[labels[index]-'a'];
        return count;
    }
    
    
    
    
    
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> ans(n,0);
        vector<bool> visited(n,false);
        
        
        vector<vector<int>> adj_list(n);
        for(int i = 0; i < edges.size(); i++){
            int x = edges[i][0];
            int y = edges[i][1];
            adj_list[x].push_back(y);
            adj_list[y].push_back(x);
        }
        
        DFS(0,ans,visited,adj_list,labels);
        return ans;
        
        
        
    }
};
