class Solution {
public:
    int mod = 1000000007;
    int numSub(string s) {
       long int count = 0;
        int ans = 0;
        for(int i = 0 ; i < s.length(); i++){
            if(s[i] == '1') (count++) ;
            else{
                ans = (ans+(((count)*(count+1)))/2) %mod ;
             
                count = 0;
            }
        }
        ans = (ans+(((count)*(count+1))/2)) %mod;
        return ans;
        
    }
};
