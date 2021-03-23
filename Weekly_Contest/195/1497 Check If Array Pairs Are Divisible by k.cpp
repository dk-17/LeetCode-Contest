class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> umap;
        for(int i = 0; i < arr.size(); i++){
             int rem = arr[i] % k;
            
            if(rem < 0) rem +=k;
            umap[rem]++; 
        }
       
        for(int i = 0; i < arr.size(); i++){
            int rem =  arr[i] % k;
            if(rem < 0) rem +=k;
         
            if(rem == 0 && (umap[rem] % 2 ) != 0)return false;
             else if(rem != 0 && umap[rem] != umap[k - rem])   return false;
            
        }
        return true;
        
    }
};

// if a % k = x;
//    b % k = k - x;
//    (a+b) % k = 0;
