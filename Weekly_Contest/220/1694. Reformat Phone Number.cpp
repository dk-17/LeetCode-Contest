class Solution {
public:
    string reformatNumber(string number) {
        string s="";
        for(int i=0;i<number.length();i++){
            if(isdigit(number[i]))
                s+=number[i];
        }
        string ans="";
        int i=0;
        int n= s.length();
        while(i<n){
            if(n-i == 4){
                ans+=s.substr(i,2);
                ans+='-';
                ans+=s.substr(i+2,2);
                i+=4;
            }
            else if(n-i==2){
                ans+=s.substr(i,2);
                i+=2;
            }
            else{
                ans+=s.substr(i,3);
                i+=3;
                if(i>=n)
                    continue;
                else
                    ans+='-';
            }
        }
        return ans;
        
    }
};
