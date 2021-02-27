class Solution {
public:
    int getMaximumGenerated(int n) {
        vector<int> v;
        v.push_back(0);
        v.push_back(1);
        for(int i=2;i<=n;i++){
            if(i%2==0){
                v.push_back(v[i/2]);
            }
            else 
                v.push_back(v[i/2]+v[(i/2)+1]);
        }
        int ans=INT_MIN;
        for(int i=0;i<=n;i++){
           
            
            if(ans<v[i])
            ans=v[i];
            
        }
        //cout<<endl;
        return ans;
    }
};
