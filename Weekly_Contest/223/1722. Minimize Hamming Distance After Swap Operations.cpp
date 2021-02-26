vector<int> parent;
class Solution {
public:
     int find(int a){
     if(parent[a]==a)
     return parent[a];
     
     return parent[a]=find(parent[a]);
     }

    

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n=source.size();
        parent.resize(n);
        for(int i=0;i<n;i++)
            parent[i]=i;
        
        for(int i=0;i<allowedSwaps.size();i++){
            int a= find(allowedSwaps[i][0]);
            int b= find(allowedSwaps[i][1]);
          
            if(a!=b)
            parent[b]=a;       
        }
       
       
        
     vector<unordered_multiset<int>> group(n);
        for(int i=0;i<n;i++)
            group[find(i)].insert(source[i]);
        
     
        
        
        int ans=0;
        for(int i=0;i<n;i++){
         
            if(!group[parent[i]].count(target[i]))
                ans++;
            else
                group[parent[i]].erase(group[parent[i]].find(target[i]));
            
        }
        return ans;
        
    }
};
