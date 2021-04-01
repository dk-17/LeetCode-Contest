class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> prefix(n,vector<int>(m,0));
        
        //row
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m ; j++){
                if(j == 0)
                    prefix[i][j] = matrix[i][j];
                else
                    prefix[i][j] = prefix[i][j-1] ^ matrix[i][j];
            }
        }
        //column
        for(int j = 0; j < m; j++){
            for(int i = 1; i < n; i++){
                prefix[i][j] ^= prefix[i-1][j];
            }
        }
        
        vector<int> ans;
        for(int i = 0; i< n; i++){
            for(int j = 0; j < m; j++){
                ans.push_back(prefix[i][j]);
            }
        }
        
        sort(ans.begin(),ans.end(),greater<int>());
        return ans[k-1];
        
    }
};
