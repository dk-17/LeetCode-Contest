class Solution {
public:
    bool islucky(vector<vector<int>>& matrix,int i,int j){
        for(int k = 0; k < matrix.size();k++){
            if(matrix[k][j] > matrix[i][j]) return false;
        }
        for(int k = 0; k < matrix[0].size();k++){
            if(matrix[i][k] < matrix[i][j]) return false;
        }
        return true;
    }
    
    
    
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ans;
        int min_valRow = INT_MAX;
        int max_valCol = INT_MIN;
        for(int i = 0; i < matrix.size();i++){
            for(int j = 0; j < matrix[0].size();j++){
                if(islucky(matrix,i,j))
                 ans.push_back(matrix[i][j]);
            }
        }
        return ans;
        
        
    }
};
