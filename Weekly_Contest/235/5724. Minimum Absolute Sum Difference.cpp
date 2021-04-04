class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int mod = 1e9 + 7;
        for(int i = 0 ; i< nums1.size(); i++){
            ans.push_back(abs(nums1[i]- nums2[i]));
        }
        int index = 0;
        int max_val = ans[0];
        for(int i = 1; i < nums1.size(); i++){
            if(max_val < ans[i]){
                max_val = ans[i];
                index = i;
            }
        }
        
      //  cout<<"index= "<<index<<endl;
        int add = INT_MAX;
        for(int i = 0; i < nums1.size(); i++){
            add= min(add,abs(nums2[index] - nums1[i]));
        }
        long long int total = 0;
        for(int i =0; i< ans.size(); i++){
            if(i == index)
                total+=add;
            else
                total+=ans[i];
        }
        return total % mod;
        
    }
};
