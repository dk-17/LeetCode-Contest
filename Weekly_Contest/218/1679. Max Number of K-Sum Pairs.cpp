class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n=nums.size();
       
        int i=0,j=n-1;
        int count=0;
        sort(nums.begin(),nums.end());
        int sum=0;
        while(i<j){
            sum=nums[i]+nums[j];
            if(sum<k){
                i++;
            }
            else if(sum>k)
                j--;
            else if(sum==k){
                count++;
                i++;
                j--;
            }
        }
       
        return count;
    }
};
