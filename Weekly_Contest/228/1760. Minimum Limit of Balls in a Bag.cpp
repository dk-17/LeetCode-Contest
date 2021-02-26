class Solution {
public:
    bool check(int mid,vector<int>& nums,int o){
        int count=0;
        for(int i=0;i<nums.size();i++){
            count+=(nums[i]-1)/mid;
            
        }
        if(count>o)
            return false;
        return true;
    }
    
    
    int minimumSize(vector<int>& nums, int o) {
        int ans=0;
        int l=1,r=1000000000;
        int mid=0;
        while(l<=r){
            mid=l+(r-l)/2;
            if(check(mid,nums,o)){
                ans=mid;
                r=mid-1;
            }
               else
               l=mid+1;
        }
        return ans;
    }
};
