class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n=nums.size();
        stack<int> s;
        s.push(nums[0]);
        vector<int> ans(k,0);
        for(int i=1;i<n;i++){
         
            if(!s.empty()&&nums[i]<s.top()){
                while(!s.empty()&&s.size()+n-(i+1)>=k&&nums[i]<s.top())
                            s.pop();    
            } 
            s.push(nums[i]);
        }
       
        while(!s.empty()&&s.size()!=k)
            s.pop();
        for(int i=k-1;i>=0;i--){
            ans[i]=s.top();
            s.pop();
        }
        return ans;
    }
};
