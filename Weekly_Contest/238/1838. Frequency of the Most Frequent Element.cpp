class Solution {
public:
    int maxFrequency(vector<int>& nums, long k) {
        int ans = 0;
        sort(nums.begin(),nums.end());
        int i = 0,j = 0;
        
        while( j <nums.size()){
            k +=nums[j];
            while( k < (long)(j-i+1)*nums[j]){
                k -= nums[i++];
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
