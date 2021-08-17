class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
     
        int n = nums.size();
        vector<int> s;
        vector<int> l;
        for(int i =0; i <= nums.size()/2; i++){
            s.push_back(nums[i]);
        }
        for(int i = nums.size()/2 + 1; i < nums.size(); i++){
            l.push_back(nums[i]);
        }
        nums.clear();
        int i = 0,j = 0;
        while( i < s.size() && j < l.size()){
            nums.push_back(s[i++]);
            nums.push_back(l[j++]);
        }
        while(i < s.size()){
            nums.push_back(s[i++]);
        }
        while(j < l.size()){
            nums.push_back(l[j++]);
        }
        
        return nums;
        
    }
};
