class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> ans;
        int start = rounds[0];
        int size = rounds.size();
        int end = rounds[size - 1];
        if(start <= end){
            for(int i = start ; i <= end; i++ ){
                ans.push_back(i);
            }
            return ans;
        }
        else{
            for(int i = 1; i <=end; i++)
                ans.push_back(i);
            
           
            for(int i = start ; i <= n; i++)
              ans.push_back(i);
        }
        
        return ans;
        
        
        
    }
};
