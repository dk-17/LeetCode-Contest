class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
       long long int ans = 0;
        int mod = 1e9 + 7;
        int n =nums1.size();
        vector<int> diff;
        for(int i= 0; i < nums1.size(); i++){
            diff.push_back(abs(nums1[i] - nums2[i]));
            ans+=diff[i];
        }
     
        vector<int> arr(nums1.size());
        sort(nums1.begin(),nums1.end());
        for(int i = 0; i < nums1.size(); i++){
            int j  = lower_bound(nums1.begin(),nums1.end(),nums2[i]) - nums1.begin();
            if(j!=0 && j != n)
                arr[i] = min(abs(nums2[i]- nums1[j]),abs(nums2[i]- nums1[j-1]));
            else if(j == 0)
                arr[i] = abs(nums2[i] - nums1[j]);
            else
                arr[i] = abs(nums2[i] - nums1[j-1]);
        }
        
        int best  = 0;
        for(int i = 0; i< arr.size(); i++)
            best = max(best,diff[i]-arr[i]);
    
        return (ans-best) % mod;
        
    }
};
