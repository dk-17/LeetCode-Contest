class Solution {
public:
    static bool comp(int a,int b){
        return a>b;
    }
    int minSetSize(vector<int>& arr) {
        
         vector<int> v(100001,0);
        for(int i = 0; i<arr.size();i++){
            v[arr[i]]++;
        }
        sort(v.begin(),v.end(),comp);
        int n = arr.size();
        int k = n/2;
        int i = 0;
        int count = 0;
        while(n > k){
            n -= v[i++];
            count++;
        }
   return count;
        
        
        
    }
};
