class Solution {
public:
    int specialArray(vector<int>& nums) {
        int m = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++){
            if( nums[i]>=m){
                if(i!=0 && nums[i-1]>=m)
                    return -1;
                return m;
            }
            m--;
        }
        return -1;
        
    }
};
