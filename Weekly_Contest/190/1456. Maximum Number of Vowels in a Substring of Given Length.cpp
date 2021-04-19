class Solution {
public:
    int maxVowels(string s, int k) {
        int max_count = 0;
        int count = 0;
        for(int i = 0; i<k; i++){
            if(s[i] == 'a' || s[i] == 'o' || s[i] == 'e' || s[i] == 'i' || s[i] == 'u'){
                count++;
            }
        }
        int i = 0, j =k;
        max_count =  count;
        
        while(j < s.length()){
              if( s[i] == 'a'|| s[i] == 'o' || s[i] == 'e' || s[i] == 'i' || s[i] == 'u'){ 
                if(count!=0)
                    count--;
            }
             if(s[j] == 'a' || s[j] == 'o' || s[j] == 'e' || s[j] == 'i' || s[j] == 'u'){
                count++;
            }
            
            j++;
            i++;
            max_count = max(max_count,count);
        }
        return max_count;
        
    }
};
