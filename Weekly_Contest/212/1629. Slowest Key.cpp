class Solution {
public:
    char slowestKey(vector<int>& rt, string k) {
       char ans;
        int n=rt.size();
        vector<int> v(n,0);
        v[0]=rt[0];
        for(int i=1;i<rt.size();i++){
            v[i]=rt[i]-rt[i-1];
        }
        
        int max_time=0;
        int index=0;
        for(int i=0;i<rt.size();i++){
            if(max_time==v[i]){
                ans = max(ans,k[i]);
            }
            if(max_time<v[i]){
                max_time=v[i];
                 ans=k[i];
            }
        }
        
        
        
        return ans;
    }
};
