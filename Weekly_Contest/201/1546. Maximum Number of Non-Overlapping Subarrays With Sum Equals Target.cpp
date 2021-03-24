class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_map<int,int> umap;
        int count = 0;
        int sum = 0;
        umap[0]++;
        for(int i = 0 ; i < nums.size(); i++){
           sum += nums[i];
            if(umap.find(sum - target) != umap.end()){
                count++;
                umap.clear();
                umap[0]++;
                 sum = 0;
            }
            else
            umap[sum]++;
        }
        return count;
        
    }
};
