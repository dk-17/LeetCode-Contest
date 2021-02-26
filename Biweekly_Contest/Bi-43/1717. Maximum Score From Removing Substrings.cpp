class Solution {
public:
      int remove_ba(string & s){
        int count=0;
        stack<char> st;
        for(int i=0;i<s.length();i++){
            
            if(!st.empty() && st.top()=='b' && s[i]=='a'){
                st.pop();
                count++;
            }
            else
                st.push(s[i]);
        }
        
        s="";
        while(!st.empty()){
            s+=st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());
        
        
        
        return count;
    }
    
    
    int remove_ab(string & s){
        int count=0;
        stack<char> st;
        for(int i=0;i<s.length();i++){
            
            if(!st.empty() && st.top()=='a' && s[i]=='b'){
                st.pop();
                count++;
            }
            else
                st.push(s[i]);
        }
        
        s="";
        while(!st.empty()){
            s+=st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());
        
        
        
        return count;
    }
    
    
    
    int maximumGain(string s, int x, int y) {
        int ans=0;
        int sum_ab=0,sum_ba=0;
        if(x>y){
             sum_ab=remove_ab(s);
             sum_ba=remove_ba(s);
            
        }
        else{
            sum_ba=remove_ba(s);
            sum_ab=remove_ab(s);
        }
        
        ans=sum_ab*x+sum_ba*y;
        return ans;
        
    }
};
