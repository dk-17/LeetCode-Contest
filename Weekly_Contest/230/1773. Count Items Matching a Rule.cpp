class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int count=0;
        int check;
        if(ruleKey.compare("type")==0)
            check=0;
        if(ruleKey.compare("color")==0)
            check=1;
        if(ruleKey.compare("name")==0)
            check=2;
        
        for(int i=0;i<items.size();i++){
            string s=items[i][check];
            if((s.compare(ruleValue))==0)
                count++;
        }
        return count;
        
        
    }
};
