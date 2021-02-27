class Solution {
public:
    int solve(vector<int>& dp,vector<int>& nums,int k,int index){
        if(index>=nums.size())
            return INT_MIN;
        if(index==nums.size()-1)
            return nums[index];
        if(dp[index]!=INT_MIN)
            return dp[index];
        
      
        int temp=INT_MIN;
        for(int i=1;i<=k;i++){
            dp[index]=max(dp[index],solve(dp,nums,k,index+i));
            if(index+i<nums.size()&&nums[index+i]>=0)
               break;
          
        }
        // cout<<"temp="<<temp<<endl;
       
        
        return dp[index]+=nums[index];
    }
    
    
    
    
    int maxResult(vector<int>& nums, int k) {
        vector<int>dp(nums.size()+1,INT_MIN);
       return solve(dp,nums,k,0);
    
    }
};
