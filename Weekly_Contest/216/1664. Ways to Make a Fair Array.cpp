class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n=nums.size();
        vector<int> even_sum(n+1,0),odd_sum(n+1,0);
        int even=0,odd=0,count=0;
        for(int i=0;i<n;i++){
            if(i%2==0){
                even+=nums[i];
            }
            else
                odd+=nums[i];
            even_sum[i+1]=even;
            odd_sum[i+1]=odd;
        }
        
        for(int i=1;i<=n;i++){
            even=even_sum[i-1]+odd_sum[n]-odd_sum[i];
            odd=odd_sum[i-1]+even_sum[n]-even_sum[i];
            if(even==odd)count++;
        }
        return count;
    }
};
