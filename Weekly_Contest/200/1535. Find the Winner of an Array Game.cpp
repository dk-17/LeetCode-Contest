class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        if(k >= arr.size()){
            int ans = INT_MIN;
            for(int i = 0 ; i< arr.size();i++)
                ans = max(ans,arr[i]);
            
            return ans;
        }
        map<int,int> umap;
        vector<pair<int,int> > v;
        int i =0 , j = 1;
        while(j<arr.size()){
            if(arr[i] > arr[j]){
                umap[arr[i]]++;
                if(umap[arr[i]] == k) return arr[i];
                j++;
            }
            else {
                umap[arr[i]] = 0;
                umap[arr[j]]++;
                if(umap[arr[j]] == k) return arr[j];
                i = j;
                j++;
            }
        }
        int ans = 0;
        for(auto it = umap.begin(); it!= umap.end(); it++){
            if(it->second >= k) ans =  it->first;
           // cout<<"ans = "<<ans<<endl;
        }
        if(ans == 0)
         return arr[i];
        return ans;
        
    }
};
