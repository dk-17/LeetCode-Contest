class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> umap;
        for(int i=0; i<edges.size();i++){
            int x = edges[i][0];
            int y = edges[i][1];
            umap[x]++;
            umap[y]++;
        }
        
        int n=umap.size();
        for(auto it = umap.begin(); it!=umap.end();it++){
           // cout<<"it->first= "<<it->first <<" it->second= "<<it->second<<endl;
            if(it->second ==(n-1))
                return it->first;
        }
        return -1;
        
    }
};
