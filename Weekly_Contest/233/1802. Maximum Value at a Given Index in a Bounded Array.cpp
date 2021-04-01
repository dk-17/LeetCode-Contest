class Solution {
public:
    
    long Calculate(int index, int a,int n){
        long total = 0;
        int first_element = max(a - index,0);
        int last_element =  max(a - (n-1 - index),0);
        long left_sum = (long)(first_element + a)*(a - first_element + 1 ) /2;
        long right_sum =(long) (a + last_element) * (a - last_element +1) /2;
        
        total = left_sum + right_sum - a;
       
        return total;
    }
    
    
    int maxValue(int n, int index, int maxSum) {
        maxSum -= n;//as all element must be positive so zero is neither positive nor negative hence all element at least value 1;
        int left = 0, right = maxSum;
      
        int ans = 0;
        while(left <=right){
            int mid = left + (right - left)/2;
            if(Calculate(index,mid,n) <= maxSum){
                ans = mid;
                left = mid+1;
            }
            else
                right = mid - 1;
        }
        return ans+1;// + 1 beacause initially we already given 1 element at all index;
        
        
    }
};
