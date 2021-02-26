class Solution {
public:
    int minOperations(string s) {
        int count=0;
        int curr=0;
        int ans=0;
        curr=1;
        string s1=s;
         if(s[0]!='1'){
                count++;
                s[0]='1';
            }
        for(int i=0;i<s.length()-1;i++){
          
           
             if(s[i]==s[i+1]){
                count++;
               
                if(s[i]=='0')
                    s[i+1]='1';
                else
                    s[i+1]='0';
            }
            
                
        }
     //  cout<<"count= "<<count<<endl;
        ans=count;
        curr=0;
        count=0;
         if(s1[0]!='0'){
              
                count++;
               
                s1[0]='0';
            }
         for(int i=0;i<s1.length()-1;i++){
             // cout<<"loop count= "<<count<<endl;
           
             if(s1[i]==s1[i+1]){
                count++;
                if(s1[i]=='1')
                    s1[i+1]='0';
                else
                    s1[i+1]='1';
            }
        }
       // cout<<"count= "<<count<<endl;
        ans=min(ans,count);
        return ans;
    }
};
