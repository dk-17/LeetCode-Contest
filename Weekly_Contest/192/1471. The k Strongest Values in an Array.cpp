class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int m = arr[(n-1)/2];
      //  cout<<"m= "<<m<<endl;
        vector<pair<int,int>> v;
        for(int i = 0; i<n; i++){
            v.push_back({abs(arr[i]-m),arr[i]});
            
        }
        sort(v.begin(),v.end());
        vector<int> ans;
        int i = n-1;
        while(k--){
            ans.push_back(v[i--].second);
        }
        return ans;
        
    }
};
