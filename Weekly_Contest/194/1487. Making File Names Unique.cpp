class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string,int> umap;
        vector<string> ans;
        for(int i = 0; i < names.size(); i++){
            if(umap.find(names[i]) == umap.end()){
                umap[names[i]]++;
                ans.push_back(names[i]);
            }
            else{
               
                int number = umap[names[i]] ;
                umap[names[i]]++;
             
                string s = names[i]+'('+ to_string(number) + ')';
                while(umap.find(s) !=umap.end()){
                    number++;
                    s = names[i] + '(' + to_string(number)+')';
                }
                umap[s]++;
                
                ans.push_back(s);
            }
        }
        return ans;
        
    }
};
