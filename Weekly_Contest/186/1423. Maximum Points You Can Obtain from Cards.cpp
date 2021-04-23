class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
    
        int n = cp.size() ;
        int total = 0;
        for(int i = 0; i< n; i++) total += cp[i];
        int min_sum = 0;
        int sum = 0;
        int j = 0;
        while(j < n-k){
            sum+= cp[j++];
        }
      //  cout<<"sum= "<<sum<<endl;
        min_sum = sum;
        int i = 0;
        while(j<n){
            sum += cp[j++];
            sum -= cp[i++];
            min_sum = min(min_sum,sum);
        }
        return total - min_sum;
        
    }
};
