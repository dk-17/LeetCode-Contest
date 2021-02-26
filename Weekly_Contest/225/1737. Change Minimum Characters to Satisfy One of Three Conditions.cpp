class Solution {
public:
    int minCharacters(string a, string b) {
        int ans=0;
        vector<int> count_a(26,0);
        vector<int> count_b(26,0);
         int n=a.length();
        int m=b.length();
        
        for(int i=0;i<a.length();i++)
            count_a[a[i]-'a']++;
        for(int i=0;i<b.length();i++)
            count_b[b[i]-'a']++;
        
        //for thrid condition!
        int max_freq=0;
        for(int i=0;i<26;i++)
            max_freq=max(max_freq,count_a[i]+count_b[i]);
        ans=max(ans,m+n-max_freq);
        
        int sum_a=0;
        int sum_b=0;
       
        for(int i=0;i<25;i++){
            sum_a+=count_a[i];
            sum_b+=count_b[i];
            
            ans=min(ans,sum_b + n-sum_a);
        }
        
        sum_a=0,sum_b=0;
        for(int i=0;i<25;i++){
            sum_a+=count_a[i];
            sum_b+=count_b[i];
            
            ans=min(ans,sum_a + m-sum_b);
        }
        
        return ans;
        
    }
};
