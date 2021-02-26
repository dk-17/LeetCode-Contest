class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        unordered_map<int,int> umap;
        for(int i=0;i<rectangles.size();i++){
            int l=rectangles[i][0];
            int w=rectangles[i][1];
            umap[min(l,w)]++;
        }
        int ans=0;
        int check=0;
        for(auto it=umap.begin();it!=umap.end();it++){
            if(check<it->first){
                check=it->first;
                ans=it->second;
        }}
        return ans;
    }
};
