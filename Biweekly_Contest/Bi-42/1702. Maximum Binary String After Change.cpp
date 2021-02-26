class Solution {
public:
    string maximumBinaryString(string b) {
        int start=0;
        for(int i=0;i<b.length();i++){
            if(b[i]=='1') start++;
            else break;
        }
        if(start==b.length()) return b;
     
        int zeros=0;
        for(int i=start;i<b.length();i++){
            if(b[i]=='0')
                zeros++;
        }
        
        string ans(b.length(),'1');
       
        ans[start+zeros-1]='0';
                
        return ans;
        
    }
};
