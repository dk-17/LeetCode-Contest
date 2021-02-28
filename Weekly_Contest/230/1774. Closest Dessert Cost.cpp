class Solution {
public:
    vector<int> ans;
    void calculate(vector<int>& tc,int index,int n,int cost){
        if(index>=n){
            ans.push_back(cost);
            return;
        }
        
        for(int i=0;i<3;i++){
            cost+=tc[index]*i;
            calculate(tc,index+1,n,cost);
            cost-=tc[index]*i;
        }
        
        return; 
    }
    
    
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        ans.clear();
        int cost=0;
        int base=0;
        int n=toppingCosts.size();
        calculate(toppingCosts,0,n,cost);
        vector<int> v(ans.size(),0);
        int index=0;
        vector<int> result;
        int actual_target=target;
        int min_value;
        for(int i=0;i<baseCosts.size();i++){
              min_value=INT_MAX;
              base=baseCosts[i];
              target-=base;    
            for(int j=0;j<ans.size();j++)
                v[j]=abs(target-ans[j]);
            
           
            for(int j=0;j<v.size();j++){
                if(min_value>v[j]){
                    min_value=v[j];
                    index=j;
                }           
            } 
            result.push_back(base+ans[index]);
            target=actual_target;
        }
        v.clear();
        int k=result.size();
        v.resize(k,0);
        min_value=INT_MAX;
        for(int i=0;i<result.size();i++){
            v[i]=abs(actual_target-result[i]);
            if(v[i]<min_value){
                min_value=v[i];
                index=i;
            }
                
        }
        
        return result[index];
        
    }
};
