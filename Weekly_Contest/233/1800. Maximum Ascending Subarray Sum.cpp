class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum = nums[0];
        int max_sum =0;
        for(int i = 1; i < nums.size(); i++){
           // cout<<"sum = "<<sum<<endl;
            if(nums[i] < nums[i-1]){
                if(max_sum < sum)
                    max_sum = sum;
                sum = nums[i];

                }
            else if(nums[i] != nums[i-1])
                sum+=nums[i];
            else if(nums[i] == nums[i-1]){
                if(max_sum < sum)
                    max_sum = sum;
                sum = nums[i];
            }
                
        }
        if(max_sum < sum)
            max_sum = sum;
        return max_sum;
        
    }
};
