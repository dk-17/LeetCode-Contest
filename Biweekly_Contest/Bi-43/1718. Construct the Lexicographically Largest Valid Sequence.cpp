class Solution {
public:
    vector<int> used;
    
    bool DFS(vector<int>& ans,int index){
        if(index==ans.size()) return true;
        if(ans[index])
            return DFS(ans,index+1);
        for(int j=used.size()-1;j>0;j--){
            if(used[j])
                continue;
            if(j!=1 && (index+j>=ans.size() || ans[index+j] ))
                continue;
            used[j]=1;
            ans[index]=j;
            if(j!=1) ans[index+j]=j;
            
            if(DFS(ans,index+1))
                return true;
            
            used[j]=0;
            ans[index]=0;
            if(j!=1) ans[index+j]=0;
        }
        
        return false;
    }   
    
    vector<int> constructDistancedSequence(int n) {
        
        vector<int> ans((n-1)*2+1,0);
        used.resize(n+1,0);
        DFS(ans,0);
        return ans;
        
        
        
    }
};
