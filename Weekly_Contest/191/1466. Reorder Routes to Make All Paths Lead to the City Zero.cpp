//BFS solution!
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& c) {
        vector<vector<int>> out(n),in(n);
        vector<bool> visited(n,false);
        for(int i = 0; i <(int)c.size();i++){
            int x = c[i][0];
            int y = c[i][1];
            out[x].push_back(y);
            in[y].push_back(x);
            
        }
        
        //bfs
        queue<int> q;
        q.push(0);
        int ans = 0;
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            visited[temp] = true;
            for(int i = 0; i<out[temp].size();i++){
                int node = out[temp][i];
                if(!visited[node]){
                    ans++;
                    q.push(node);
                }
            }
            for(int i = 0; i<in[temp].size();i++){
                int node = in[temp][i];
                if(!visited[node]){
                    q.push(node);
                }
            }
        }
        return ans;
        
    }
};



//DFS solution!
class Solution {
public:
    int ans;
    vector<vector<int>> out,in;
    vector<int> visited;
    void DFS(int node){
        visited[node] = true;
        for(int i = 0; i< out[node].size();i++){
            int x = out[node][i];
            if(!visited[x]){
                ans++;
                DFS(x);
            }
        }
        
        
        for(int i = 0; i< in[node].size();i++){
            int x = in[node][i];
            if(!visited[x]){
                DFS(x);
            }
        }
        
    }   
    
    int minReorder(int n, vector<vector<int>>& c) {
     out.resize(n);
        in.resize(n);
        visited.resize(n,false);
        
        ans = 0;
        for(int i = 0; i < c.size(); i++){
            int x = c[i][0];
            int y = c[i][1];
            out[x].push_back(y);
            in[y].push_back(x);
        }
        
        
        DFS(0);
        return ans;
        
        
    }
};


