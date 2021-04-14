class Solution {
public:
    bool calculate(int days ,vector<int>& a,int m,int k){
        int count= 0;
        int ans = 0;
        
        for(int i =0; i < a.size(); i++){
        
            if(a[i]<= days)
                count++;
            else 
                count = 0;
            if(count==k){
                count = 0;
                ans++;
            }
            if(ans == m) return true;
        }
        return false;
    }
    
    
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int left = INT_MAX;
        int right = INT_MIN;
        if(m*k > bloomDay.size()) return -1;
        
        
        for(int i = 0; i < bloomDay.size(); i++){
            left = min(left,bloomDay[i]);
            right = max(right,bloomDay[i]);
        }
        
        int ans = -1;
        while(left <= right){
            int days = left + (right - left)/2;
            
            if(calculate(days,bloomDay,m,k)){
                ans = days;
                right = days-1;
            }
            else
                left = days+1;
        }
        return ans;
        
        
        
        
    }
};
