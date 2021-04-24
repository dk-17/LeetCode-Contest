class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ans = 0;
        deque<int> max_val;
        deque<int> min_val;
        int i = 0;
        int j = 0;
        for( j = 0; j < nums.size();j++){
            while(!max_val.empty()&& nums[max_val.back()] < nums[j]) max_val.pop_back();
            while(!min_val.empty() && nums[min_val.back()] > nums[j]) min_val.pop_back();
            max_val.push_back(j);
            min_val.push_back(j);
            if(nums[max_val.front()] - nums[min_val.front()] > limit){
                if(min_val.front() == i) min_val.pop_front();
                if(max_val.front() == i) max_val.pop_front();
                i++;
            }
        }
        return j-i;
    }
};
