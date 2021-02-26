class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int ans=0;
        int mod=1000000007;
        for(int i=1;i<nums.size();i++)
            nums[i]+=nums[i-1];
        
        int n=nums.size();
        int j=0,k=0;
        for(int i=0;i<n-2;i++){
            while(j<=i||(j<n-1 && nums[j]<2*nums[i]))
                j++;
            while(k<j ||(k<n-1 && nums[k]-nums[i]<=nums[n-1]-nums[k]))
                k++;
            //cout<<"i= "<<i<<"j= "<<j<<"k= "<<k<<endl;
            ans=(ans+k-j)%mod;
        }
        return ans;
    }
};
