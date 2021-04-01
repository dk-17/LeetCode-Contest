class Solution {
public:
    vector<int>parent,rank,count,groupCount;
        int find(int x){
            if(parent[x] == x ) return x;
            return parent[x] = find(parent[x]);
        }
    
    
    void _union(int x,int y){
        int parent_x = find(x);
        int parent_y = find(y);
        
        if(parent_x != parent_y){
            groupCount[count[parent_x]]--;
            groupCount[count[parent_y]]--;
            count[parent_x] = count[parent_y] = count[parent_x] + count[parent_y];
            groupCount[count[parent_x]]++;
            
            rank[parent_x] < rank[parent_y] ? parent[parent_x] = parent_y : parent[parent_y] = parent_x;
            
            if(rank[parent_x] == rank[parent_y])
                rank[parent_x]++;
            
        }
        
    }
    
    
    
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        parent.resize(n+1,0);
        for(int i = 1; i <= n ;i++)
            parent[i] = i;
        rank.resize(n+1,0);
        count.resize(n+1,1);
        groupCount.resize(n+1,0);
        vector<bool> visited(n+1,false);
        int ans = -1;
        int step = 1;
        for(int i = 0; i < n; i++){
            int a = arr[i];
            groupCount[1]++;
            
            if(a+1 <= n && visited[a+1])
                _union(a,a+1);
            if(a-1 > 0 && visited[a-1])
                _union(a-1,a);
            
            visited[a]= true;
            if(groupCount[m])
                ans = step;
            step++;
            
        }
        return ans;
        
        
        
    }
};
