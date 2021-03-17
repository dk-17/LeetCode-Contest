class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for(int i = 0; i < s.length(); i++){
           
            if(st.empty()) st.push(s[i]);
            else if(!st.empty() && (islower(st.top()) && isupper(s[i]) && s[i]+32 == st.top()))
                st.pop();
            else if(!st.empty() && (isupper(st.top()) && islower(s[i]) && st.top()+32 == s[i]))
                st.pop();
            else
                st.push(s[i]);
                
        }
        string ans="";
        while(!st.empty()){
            ans +=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
