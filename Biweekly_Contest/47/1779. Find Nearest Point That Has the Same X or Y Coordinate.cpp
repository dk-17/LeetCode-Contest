class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        vector<vector<int>> v;
        for(int i=0;i<points.size();i++){
            int x1=points[i][0];
            int y1= points[i][1];
            if(x1==x || y1==y)
            v.push_back({x1,y1,i});
            
        }
       // cout<<v.size()<<endl;
        
        int ans=INT_MAX,index =-1;
        for(int i=0;i<v.size();i++){
            int x1=v[i][0];
            int y1=v[i][1];
            
            if(ans >abs(x1-x)+abs(y1-y)){
                ans =abs(x1-x)+abs(y1-y);
                index=v[i][2];
            }
            
            
        }
        
        return index;
        
    }
};
