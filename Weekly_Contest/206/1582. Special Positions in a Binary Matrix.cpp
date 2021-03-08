class Solution {
public:
        
        bool row_check(int p,int q,int m,vector<vector<int>> & mat)
        {
                for(int i=0;i<m;i++)
                {
                        if(i!=q&&mat[p][i]==1)
                        {
                                return false;
                        }
                }
                return true;
        }
           bool col_check(int p,int q,int n,vector<vector<int>> & mat)
        {
                for(int j=0;j<n;j++)
                {
                        if(j!=p&&mat[j][q]==1)
                        {
                                return false;
                        }
                }
                return true;
        }
        
    int numSpecial(vector<vector<int>>& mat) {
        int count=0;
          
            int n=mat.size();
            int m=mat[0].size();
            
            for(int i=0;i<n;i++)
            {
                    for(int j=0;j<m;j++)
                    {
                            if(mat[i][j]==1)
                            {
                                    if(row_check(i,j,m,mat)&&col_check(i,j,n,mat))
                                            count++;
                            }
                 
                    }
                    }        
            return count;
    }
};
