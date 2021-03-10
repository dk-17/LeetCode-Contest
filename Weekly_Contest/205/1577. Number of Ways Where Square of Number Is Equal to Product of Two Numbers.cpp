class Solution {
public:
    
    int solve(long  i ,vector<int>& nums){
          long long int target = i * i;
        int count = 0;
         unordered_map< int,int> umap;
         for(int i = 0; i < nums.size() ; i++){
             if(target % nums[i] == 0)
               count += umap[target/nums[i]];
             umap[nums[i]]++;
         }
        return count;
    }

    
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        int ans=0;
        for(int i = 0 ; i < nums1.size();i++){
            ans += solve(nums1[i],nums2);
        }
        
        for(int i = 0; i < nums2.size(); i++){
            ans += solve(nums2[i], nums1);
        }
        
        return ans;
        
    }
};
