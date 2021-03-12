class Solution {
public:

    
    
    int beautySum(string s) {
        map<char,int> freq;
        vector<string> v;
        string str="";
       
        int ans = 0;
        for(int i=0;i<s.length();i++){
              vector<int> count(26,0);
             int max_i = INT_MIN;
             int min_i = INT_MAX;
            for(int j=i;j<s.length();j++){
                int index = s[j]-'a';
                count[index]++;
                max_i = max(max_i,count[index]);
                min_i = count[index];
                for(int k = 0; k < 26; k++){
                    if(count[k]>=1)
                        min_i = min(min_i,count[k]);
                }
              
                
                ans += max_i - min_i;
                
            }
            
        
        }
        
       return ans;
        
    }
};
