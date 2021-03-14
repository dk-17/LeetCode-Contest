class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int first=0;
        int second= 0;
        int count=0;
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i]){
                count++;
                if(count ==1)
                    first =i;
                if(count == 2)
                    second= i;
                if(count >2)return false;
                
             }
        }
        
        if(count!=0 &&s1[first] != s2[second]) return false;
        return true;
        
    }
};
