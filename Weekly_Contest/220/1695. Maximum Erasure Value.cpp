class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> umap;
        int i=0,j=0;
        int sum=0;
        int ans=INT_MIN;
        while(j<nums.size()){
            
            while(umap.find(nums[j])!=umap.end()){
                ans=max(ans,sum);
                sum-=nums[i];
                umap.erase(nums[i]);
                
                i++;
            }
            umap[nums[j]]=j;
            sum+=nums[j];
            j++;
        }
         ans=max(ans,sum);
        return ans;
    }
};
