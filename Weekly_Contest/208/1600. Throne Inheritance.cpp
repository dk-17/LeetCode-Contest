class ThroneInheritance {
public:
    unordered_map<string,vector<string>> family;
    unordered_map<string,bool> dead;
    string root;
    ThroneInheritance(string kingName) {
        root = kingName;
    }
    
    void birth(string parentName, string childName) {
        family[parentName].push_back(childName);
    }
    
    void death(string name) {
        dead[name] = true;
        
    }
    void DFS(vector<string> & ans,string root){
        if(!dead[root]) ans.push_back(root);
        for(auto it = family[root].begin();it!= family[root].end(); it++)
            DFS(ans,*it);
    }
    vector<string> getInheritanceOrder() {
        vector<string> ans;
        DFS(ans,root);
        return ans;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
