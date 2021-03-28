class Solution {
public:
    bool check(vector<int>& arr){
       
        for(int i = 0; i < arr.size(); i++){
        
            if(arr[i] != i) return false;
        }
        return true;
    }
    
    int reinitializePermutation(int n) {
        if(n == 2) return 1;
        vector<int> per;
        for(int i = 0; i < n; i++){
            per.push_back(i);
           
        }
        int k = n;
        int count = 0;
        int flag = 0;
        vector<int> arr(n,0);
        while(k--){
            if(flag) break;
            count++;
            
        for(int i = 0; i < n; i++){
            if(i % 2 == 0)
                arr[i] = per[i/2];
            else
                arr[i] = per[n/2 + (i - 1)/2];     
            
        }
           per = arr;
         if(check(arr))
             flag = 1;
         else
             flag = 0;
         
        }
        return count;
    }
};
