class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
         int n = heights.size();
         int m = heights[0].size();
         vector<vector<int>> min_distance(n,vector<int>(m,INT_MAX));
         vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
         //min heap of vector as need to store three value
         //  prioirty_queue<vector<int>,vector<vector<int>>,greater<vector<int>> > pq; vector<int> not working
        //  priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>> > pq;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
        pq.push({0,{0,0}});//first element is min_dis ,second is i, thirs is j
        min_distance[0][0] = 0;
        while(!pq.empty()){
             auto temp = pq.top();
             pq.pop();
          //   int i = get<1>(temp); ---->if using tuple then this way to access the element 
            // int j = get<2>(temp);
            
            int i = temp.second.first;
            int j = temp.second.second;
            if(i == n-1 && j == m-1) break;
            
             for(int k = 0; k < 4; k++){
                 int x = i + dir[k][0];
                 int y = j + dir[k][1];
                 
                 if(x < 0 || x >= n || y < 0 || y >= m) continue;
                 
                 int alt = max(temp.first,abs(heights[i][j] - heights[x][y]));
                 if(alt < min_distance[x][y]){
                     min_distance[x][y] = alt;
                     pq.push({alt,{x,y}});
                 }
             }
            
        }
        
        
        
        return min_distance[n-1][m-1];
        
        
        
        
    }
};
