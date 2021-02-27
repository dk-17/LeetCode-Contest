class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n=nums.size();
        unordered_map<int,int> umap;
        for(int i=0;i<n/2;i++)
            umap[nums[i]+nums[n-1-i]]++;
        vector<int> one_move(2*limit+2,0),two_move(2*limit+2,0);
        for(int i=0;i<n/2;i++){
            int min_sum=min(nums[i],nums[n-1-i])+1;
            int max_sum=max(nums[i],nums[n-1-i])+limit;
            one_move[min_sum]++;
            one_move[max_sum+1]--;
            
            two_move[2]++;
            two_move[min_sum]--;
            two_move[max_sum+1]++;
            two_move[2*limit+1]--;
            
        }
        
        for(int i=1;i<2*limit+2;i++){
            one_move[i]+=one_move[i-1];
            two_move[i]+=two_move[i-1];
            
        }
        
        for(auto it=umap.begin();it!=umap.end();it++)
            one_move[it->first]-=it->second;
        
        int ans=INT_MAX;
        for(int i=2;i<=2*limit;i++)
            ans=min(one_move[i]+2*two_move[i],ans);
        
        return ans;
    }
};
