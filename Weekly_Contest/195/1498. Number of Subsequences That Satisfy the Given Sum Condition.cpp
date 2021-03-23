class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int ans = 0;
        int mod = 1e9 + 7;
        sort(nums.begin(),nums.end());
        int i = 0, j = nums.size() - 1;
        vector<int> v(nums.size(),1);
        for(int i = 1; i < nums.size(); i++)
            v[i] = v[i -1] * 2 % mod;
        while(i <= j){
            if(nums[i] + nums[j] > target)
                j--;
            else{
                int add = v[j - i];
                ans = (ans+ add) % mod;
                i++;
            }
        }
        return ans;
        
    }
};

// Hint
//  2 ^ n = (2 ^ 0 + 2 ^ 1 + 2^2 ...+ 2^n-1 ) + 1;
