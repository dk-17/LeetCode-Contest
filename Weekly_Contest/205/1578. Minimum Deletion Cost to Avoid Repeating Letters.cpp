class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int ans = 0;
        stack<int> st;
        for(int i = 0; i < s.length(); i++){
            if(st.empty()) st.push(i);
            else if(!st.empty() && s[st.top()] == s[i]){
                if(cost[st.top()] > cost[i]){
                    ans += cost[i];
                }
                else{
                    ans += cost[st.top()];
                    st.pop();
                    st.push(i);
                }
            }
            else
                st.push(i);
        }
        return ans;
        
    }
};
