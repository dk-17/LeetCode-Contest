class Solution {
public:
    string interpret(string s) {
        
        string ans="";
        int i=0;
        int n=s.size();
        while(i<n){
          //  cout<<"i= "<<i<<endl;
            if(s[i]=='G'){
                ans+='G';
                i++;
                continue;
            }
            if(s[i]=='('&&i<n){
                if(s[i+1]==')'){
                    ans+='o';
                    i=i+2;
                    continue;
                }
                if(s[i+1]=='a'){
                    ans+="al";
                    i=i+4;
                    continue;
                }
            }
            
        }
        return ans;
    }
};
