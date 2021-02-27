class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        
        unordered_map<int,int> umap,index;
        for(int i=0;i<arr.size();i++){
            index[arr[i]]=i;
            umap[arr[i]]=1;
        }
        
        
        for(int i=0;i<pieces.size();i++){
            if(pieces[i].size()==1&&umap[pieces[i][0]]==0)
                return false;
            for(int j=0;j<pieces[i].size()-1;j++){
                if(index[pieces[i][j+1]]-index[pieces[i][j]]!=1||(umap[pieces[i][j+1]]==0||umap[pieces[i][j]]==0))
                    return false;
                if(index[pieces[i][j+1]]<index[pieces[i][j]]||(umap[pieces[i][j+1]]==0||umap[pieces[i][j]]==0))
                    return false;
            }
        }
        return true;
    }
};
