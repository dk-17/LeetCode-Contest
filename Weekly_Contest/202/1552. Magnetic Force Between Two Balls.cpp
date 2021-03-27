class Solution {
public:
    
    bool valid(vector<int>& A,int dis,int m){
        int prev = 0;
        int j = 1;
        m--;
        while(m--){
            while( j < A.size() && A[j] < A[prev] +dis) j++;
            if(j >= A.size()) return false;
            prev = j;
        }
        return true;
    }
    
    int maxDistance(vector<int>& A, int m) {
        int ans = 0;
        sort(A.begin(),A.end());
        if(m == 2) return A.back() - A[0];
        int l = 1; 
        int r = A.back() - A[0];
        while(l <= r){
            int mid = l + (r-l)/2;
            
            if(valid(A,mid,m)){
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        return ans;
        
    }
};
