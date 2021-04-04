class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int,int> umap;
        set<pair<int,int>> st;
        
           
        for(int i = 0 ; i < logs.size(); i++){
            if(st.find({logs[i][0],logs[i][1]})==st.end()){
             st.insert({logs[i][0],logs[i][1]});
            umap[logs[i][0]]++;
            }
        }
        vector<int> ans(k,0);
        for(auto it = umap.begin();it!= umap.end(); it++){
           // cout<<"it->frst = "<<it->first<<"it->seond= "<<it->second<<endl;
            int freq = it->second;
            ans[freq - 1]++;
        }
        return ans;
        
    }
};
