class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        vector<long long int> prefix(candiesCount.size(),0);
        prefix[0]=candiesCount[0];
        for(int i=1;i<candiesCount.size();i++){
            prefix[i]=prefix[i-1]+candiesCount[i];
        }
        
        vector<bool> ans;
        for(int i=0;i<queries.size();i++){
           long long int type=queries[i][0];
           long long int day=queries[i][1];
           long long int atmost=queries[i][2];
            
            if((day+1)*atmost>(type==0?0:prefix[type-1]) && prefix[type]>=(day+1)*1)
                ans.push_back(1);
            else
                ans.push_back(0);
        }
        return ans;
        
        
    }
};
