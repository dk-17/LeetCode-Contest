class Solution {
public:
    pair<int,int> Solve(vector<int>& nums,int k){
        int max_len=0;
        int sum=0;
        unordered_map<int,int> umap;
        int x=0,y=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum==k){
            max_len=max(max_len,i+1);
             x=0;
                y=i+1;
            }
            if(umap.find(sum)==umap.end())
                umap[sum]=i;
            
            if(umap.find(sum-k)!=umap.end()){
                if(max_len<i-umap[sum-k]){
                    max_len=i-umap[sum-k];
                    x=umap[sum-k];
                    y=i;
                }
            }
        }
        // cout<<"max lend= "<<max_len<<endl;
        // cout<<"x="<<x<<endl;
        // cout<<"y= "<<y<<endl;
        return {x,y};
    }
    
    
    
    
    int minOperations(vector<int>& nums, int x) {
        int total=0;
        for(int i=0;i<nums.size();i++)
            total+=nums[i];
        int k=total-x;
        if(k==0)
            return nums.size();
        pair<int,int> index=Solve(nums,k);
        int i=index.first;
        int j=index.second;
        if(i==0 && j==0)
            return -1;
        return i+nums.size()-j; 
    }
};
