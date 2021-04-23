class Solution {
public:
    int maxScore(string s) {
     int n = s.length();
        vector<int>zero(n,0),one(n,0);
        for(int i = 0; i< n;i++){
            if(i == 0 )
                zero[i] = (s[i]=='0') ? 1 : 0;
            else if(s[i]=='0')
                zero[i] = zero[i-1]+1;
            else
                zero[i]=zero[i-1];
        }
          for(int i = n-1; i>=0;i--){
            if(i == n-1 ){
                one[i] =( s[i] == '1')? 1:0;
            }
            else if(s[i]=='1')
                one[i] = one[i+1]+1;
              else
                  one[i]=one[i+1];
        }
        for(int i = 0; i< n;i++)
            cout<<one[i]<<" ";
        int ans = 0;
        for(int i = 0; i< n-1;i++){
            
            ans = max(ans,zero[i] + one[i+1]);
        }
        
        return ans;
    }
};
