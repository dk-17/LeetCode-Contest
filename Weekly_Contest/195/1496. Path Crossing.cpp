class Solution {
public:
    bool isPathCrossing(string s) {
        map<pair<int,int>,int> umap;
        int i =0, j = 0;
        umap[{0,0}]++;
        for(int k = 0; k < s.length();  k++){
            if(s[k] == 'N'){
                j++;
                if(umap.find({i,j}) != umap.end()) return true;
                else
                    umap[{i,j}]++;
            }
             if(s[k] == 'E'){
                i++;
                if(umap.find({i,j}) != umap.end()) return true;
                else
                    umap[{i,j}]++;
            }
             if(s[k] == 'S'){
                j--;
                if(umap.find({i,j}) != umap.end()) return true;
                else
                    umap[{i,j}]++;
            }
             if(s[k] == 'W'){
                i--;
               
                if(umap.find({i,j}) != umap.end()) return true;
                else
                    umap[{i,j}]++;
            }
            
            
        }
        return false;
        
    }
};
