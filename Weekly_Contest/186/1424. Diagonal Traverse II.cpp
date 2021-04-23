class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = 0;
        for(int i = 0; i< nums.size();i++)m =max(m,(int)nums[i].size());
        vector<vector<int>> v(n+m);
        for(int i = 0; i< n; i++){
            for(int j = 0; j < nums[i].size();j++){
                v[i+j].push_back(nums[i][j]);
            }
        }
        vector<int> ans;
        for(int i = 0; i< v.size();i++){
            for(int j = v[i].size()-1;j>=0;j--){
                ans.push_back(v[i][j]);
            }
        }
        return ans;
        
    }
};
