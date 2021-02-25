class Solution {
public:
    
    bool search(vector<int>& block,vector<int> & nums,int& j){
        int l,m;
        for(int i=j;i<nums.size();i++){
            if(nums[i]==block[0]){
                l=i;
                m=0;
                
                while(l<nums.size() && m<block.size()){
                    if(nums[l]!=block[m])
                        break;
                    l++;
                    m++;
                }
                if(m==block.size()){
                    j=l;
                   
                    return true;
                    
                }
            }
        }
        return false;
    }
    
    
    
    
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int n=groups.size();
         vector<int> block;
         int j=0;
        int count=0;
        for(int i=0;i<n;i++){
            block=groups[i];
            if(!(search(block,nums,j)))
                return false;
            count++;
            
        }
       // cout<<"count= "<<count<<endl;
        if(count!=n)
            return false;
        return true;
    }
    
};
