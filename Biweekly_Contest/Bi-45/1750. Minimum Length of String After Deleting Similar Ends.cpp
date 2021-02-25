class Solution {
public:
    int minimumLength(string s) {
        char current;
        int i=0,j=s.length()-1;
      //  cout<<"length= "<<s.length()<<endl;
        while(i<j){
            if(s[i]==s[j]){
                current=s[i];
                i++;
                j--;
            }
            else if(s[i]==current && s[j]!=current){
                i++;
            }
            else if(s[i]!=current && s[j]==current)
                j--;
            else if(s[i]!=s[j])
                break;
        }
        if(i==j && s[i]==current){
            return 0;
            
        }
        
        return j-i+1;
        
    }
};
