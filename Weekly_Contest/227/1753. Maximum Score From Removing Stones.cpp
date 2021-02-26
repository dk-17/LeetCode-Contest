class Solution {
public:
    int maximumScore(int a, int b, int c) {
       if(a>b)
           swap(a,b);
        if(b>c)
            swap(b,c);
        int ans=0;
        
         if((a+b)>c){
            
                int remove=(a+b)-c;
                ans=c+(remove/2);
            }
            else
                ans= a+b;
        
        
            return ans;
        
            
    }
};
