class Solution {
public:
    string reformat(string s) 
    {
        string ans="";
        vector<char> alp;
        vector<char> num;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]>=92&&s[i]<=122)
                alp.emplace_back(s[i]);
            else
                num.emplace_back(s[i]);
        }
        
        int i=0,j=0;
        if(alp.size()==0&&num.size()==1)
        {
            ans+=num[0];
            return ans;
        }
        if(num.size()==0&&alp.size()==1)
        {
            ans+=alp[0];
            return ans;
        }
        if(alp.size()==0||num.size()==0)
            return ans;
        while(i<alp.size()&&j<num.size())
        {
            if(num.size()>alp.size())
            {    ans+=num[j];
            
                j++;
            ans+=alp[i];
            i++;
            }
            else
            {ans+=alp[i];
            i++;
            ans+=num[j];
            j++;
            }
        }
        if(i<alp.size())
            ans+=alp[i];
        if(j<num.size())
            ans+=num[i];
        if(ans.length()!=s.length())
        {
            ans="";
            return ans;
        }
        
        return ans;
        
    }
};
