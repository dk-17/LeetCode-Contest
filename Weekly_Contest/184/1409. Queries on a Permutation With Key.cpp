class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m)
    {
        vector<int> ans;
        unordered_map<int,int> umap;
        for(int i=0;i<m;i++)
            umap[i+1]=i;
        for(int i=0;i<queries.size();i++)
        {
            ans.emplace_back(umap[queries[i]]);
            for(auto it=umap.begin();it!=umap.end();it++)
            {
                if(it->second<ans[i])
                    it->second++;
            }
            umap[queries[i]]=0;
            
        }
        
        return ans;
        
    }
};
