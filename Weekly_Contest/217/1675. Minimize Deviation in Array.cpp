class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n=nums.size();
        priority_queue<int> pq;
        int min_val=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]%2!=0)
              nums[i]*=2;
            pq.push(nums[i]);
            min_val=min(min_val,nums[i]);
            
        }
        int ans=INT_MAX;
        while(1){
            int temp=pq.top();//greatest element from the max heap;
            pq.pop();
            ans=min(ans,temp-min_val);
            if(temp%2!=0) break;//odd number means it will for sure increase the difference if opperaton *2 apply in odd value;
            temp/=2;
            pq.push(temp);
            if(temp<min_val)
                min_val=temp;
        }
        
        
        return ans;
    }
};
