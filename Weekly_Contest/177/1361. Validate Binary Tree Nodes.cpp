class Solution {
public:
    int flag = true;
    void DFS(vector<vector<int>>& adj_list,int node,vector<bool>& visited){
        if(visited[node]) {
            flag = false;
            return;
        }
        visited[node] = true;
        for(int i = 0; i< adj_list[node].size();i++){
            DFS(adj_list,adj_list[node][i],visited);
        }
        return ;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<vector<int>> adj_list(n);
        vector<int> parent(n,-1);
        for(int i = 0 ; i<leftChild.size();i++){
            if(leftChild[i]!=-1){
                adj_list[i].push_back(leftChild[i]);
                parent[leftChild[i]] = i;
            }
            if(rightChild[i]!=-1){
                adj_list[i].push_back(rightChild[i]);
                parent[rightChild[i]] = i;
            }
        }
  
        int root = -1;
        for(int i = 0; i < n;i++){
            if(parent[i]==-1) root = i;
        }
        if(root==-1) return false;
        vector<bool>visited(n,false);
        DFS(adj_list,root,visited);
        for(int i = 0; i < n; i++){
            if(visited[i] == 0) flag = false;
        }
        return flag;
    }
};
