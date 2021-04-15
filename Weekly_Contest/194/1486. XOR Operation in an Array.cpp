class Solution {
public:
    int xorOperation(int n, int start) 
    {
        vector<int> nums;
        int ans=1;
        ans=start;
        for(int i = 1;i<n;i++)
        {
            ans^=start+2*i;
        }
        
        return ans;
        
        
    }
};
