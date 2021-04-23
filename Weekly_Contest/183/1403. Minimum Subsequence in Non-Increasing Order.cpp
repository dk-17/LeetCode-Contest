class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        int sum = 0;
        vector<int> ans;
        int total = 0;
        for(int i = 0; i< nums.size();i++) total += nums[i];
        for(int i = 0; i < nums.size();i++){
            sum +=nums[i];
            ans.push_back(nums[i]);
            if(sum > (total - sum)) return ans; 
        }
        return ans;
        
    }
};
