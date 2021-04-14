class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> umap;
        for(int i = 0; i < arr.size(); i++)
            umap[arr[i]]++;
        
        vector<int> ans;
        for(auto it = umap.begin(); it!= umap.end(); it++){
            ans.push_back(it->second);
        }
        sort(ans.begin(),ans.end());
        int i= 0;
        int count = 0;
      
        while(i < ans.size()){
            
          
            count+= ans[i];
            i++;
            if(count == k)break;
            if(count > k){
                i--;
                break;
                
            }
            
        }
        return ans.size()-i;
        
    }
};
