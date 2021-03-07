class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
       long long int sum=0;
        for(int i=0;i<nums.size();i++) sum+=nums[i];
       long long int k= abs(goal - sum);
            if(k<0)
                k = (-1)*k;
            if(k%limit!=0)
                return k/limit +1;
            return k/limit;
        
        
        
        
    }
};
