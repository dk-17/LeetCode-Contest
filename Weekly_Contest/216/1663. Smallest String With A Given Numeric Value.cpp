class Solution {
public:
    string getSmallestString(int n, int k) {
        
        string ans(n,'a');
        int i=n;
      
        while(i--){
            if(k-i>=26){
                ans[i]=(char)(26+96);
                k-=26;
            }
            else{
                ans[i]=(char)((k-i)+96);     
                break;
            }
        }
       
       
        return ans;
        
    }
};
