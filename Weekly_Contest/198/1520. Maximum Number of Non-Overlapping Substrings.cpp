class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> first(26,n);
        vector<int> last(26,-1);
        for(int i = 0; i < n; i++){
            int index = s[i] - 'a';
            first[index] = min(first[index],i);
            last[index] = i;
        }
        
        //update first and last to make valid substring;
        for(int i = 0; i < 26; i++){
            int l = first[i];
            int r = last[i];
            for(int j = l+1; j < r; j++){
                int index = s[j]-'a';
                l = min(l,first[index]);
                r = max(r,last[index]);
            }
            
            first[i] = l;
            last[i] = r;
        }
        vector<vector<int>> subs;
        for(int i = 0; i< n; i++){
            int index = s[i] - 'a';
            if(i == first[index]){
                int r = last[index];
                if(!subs.empty() && subs.back()[1] > r){
                 
                    subs.pop_back();

                }
                
                subs.push_back({i,r});
            }
        }
        
        vector<string> ans;
        for(int i = 0; i < subs.size(); i++){
            int l = subs[i][0];
            int r = subs[i][1];
            ans.push_back(s.substr(l,r-l+1));
        }
        return ans;
        
    }
};
