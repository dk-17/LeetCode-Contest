class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        set<int> drydays;
        vector<int> ans;
        unordered_map<int,int> umap;
        for(int i = 0 ;i < rains.size(); i++){
            if(rains[i] == 0){
               drydays.insert(i);
                ans.push_back(1);
            }
            else {
                
                int lake = rains[i];
                if(umap.find(lake)!= umap.end()){
                    auto it = drydays.lower_bound(umap[lake]);
                    if(it == drydays.end()) return {};
                    
                    int day = *it;
                    ans[day] = lake;
                    drydays.erase(day);
                }
                 umap[lake] = i;
            ans.push_back(-1);
            }
           
        }
        return ans;
        
    }
};
