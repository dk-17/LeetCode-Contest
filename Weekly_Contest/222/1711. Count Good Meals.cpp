class Solution {
public:
    int countPairs(vector<int>& d) {
        unordered_map<int,int> umap;
        sort(d.begin(),d.end());
        int ans=0;
        int mod=1000000007;
        for(int i=0;i<d.size();i++){
            
            for(int j=0;j<22;j++){
                int z=1<<j;
                int y=z-d[i];
                
                if(y>d[i])
                    break;
                
                ans+=umap[y];
                ans%=mod;
                
            }
            umap[d[i]]++;
           
        }
        return ans;
    }
};
