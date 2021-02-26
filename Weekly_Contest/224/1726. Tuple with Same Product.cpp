class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> umap;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                umap[nums[i]*nums[j]]++;
            }
        }
        
        int no_of_tuples=0;
        for(auto it=umap.begin();it!=umap.end();it++){
            int k=it->second;
            no_of_tuples+=(k*(k-1))/2;
        }
        return no_of_tuples*8;
        
        
    }
};
