class Solution {
public:
    string destCity(vector<vector<string>>& v) 
    {
        string s;
        unordered_map<string,int> first;
       // umap<stirng,int> second;
        for(int i=0;i<v.size();i++)
            first[v[i][0]]++;
        
        for(int i=0;i<v.size();i++)
            if(first[v[i][1]]==0)
                s=v[i][1];
        
        
        return s;
    }
};
