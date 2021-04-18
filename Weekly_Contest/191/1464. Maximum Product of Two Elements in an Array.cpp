tc:-O(nlog(n))
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n= nums.size();
        return ((nums[n-1] - 1)*(nums[n-2]-1));
        
    }
};

tc:-O(n)
class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
      int max_a=INT_MIN;
        int max_b=INT_MIN;
        int index=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(max_a<nums[i])
            {
                max_a=nums[i];
                index=i;
            }
        }
        
        nums[index]=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
                continue;
            if(max_b<nums[i])
            {
                max_b=nums[i];
            }
        }
        
        return (max_a-1)*(max_b-1);
        
    }
};
