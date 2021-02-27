class Solution {
public:
    
    bool possible (int l,int r, vector<int>& nums){
        vector<int>block;
        for(int i=l;i<=r;i++)
            block.push_back(nums[i]);
        sort(block.begin(),block.end());
        int diff=block[1]-block[0];
        for(int i=2;i<block.size();i++){
            if(diff!=block[i]-block[i-1])
                return false;
        }
        return true;
    }
    
    
    
    
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for(int i=0;i<l.size();i++){
           ans.push_back(possible(l[i],r[i],nums));
        }
        return ans;
    }
};
