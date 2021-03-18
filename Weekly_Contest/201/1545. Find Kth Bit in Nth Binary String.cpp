class Solution {
public:
    string generate(string s,int n){
        string str= "";
        for(int i = n-1; i>=0; i--){
            if(s[i]=='1') str+='0';
            else str+='1';
        }
        return str;
        
    }
    
    
    
    char findKthBit(int n, int k) {
        vector<string>v(n);
        v.push_back("0");
        string s = "0";
        int i = 1;
        string str= "";
        while(i<n){
            int l = s.length();
            s+='1';
            s +=generate(s,l);
            v.push_back(s);
            i++;
        }
       // cout<<"s= "<<s<<endl;
        return s[k-1];
        
    }
};
