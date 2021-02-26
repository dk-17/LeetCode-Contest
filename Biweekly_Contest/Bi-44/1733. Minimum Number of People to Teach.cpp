class Solution {
public:
    bool check(vector<vector<int>>& language,int f1,int f2){
        set<int> l;
        for(int i=0;i<language[f1].size();i++){
            l.insert(language[f1][i]);
        }
        
        for(int i=0;i<language[f2].size();i++){
            if(l.count(language[f2][i])>0)
                return true;
        }
        return false;
    }
    
    
    
    
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
    set<int> dont_speak;
        for(int i=0;i<friendships.size();i++){
            int f1=friendships[i][0];
            int f2=friendships[i][1];
            if(check(languages,f1-1,f2-1))
            continue;
            dont_speak.insert(f1-1);
            dont_speak.insert(f2-1);
        }
        
        vector<int> lang(n,0);
        int max_lan=0;
        for(int i:dont_speak){
           for(int l:languages[i]){
               lang[l-1]++;
               max_lan=max(max_lan,lang[l-1]);
           }
        }
        if(dont_speak.size()==0)
            return 0;
        
        return dont_speak.size()-max_lan;
    }
};
