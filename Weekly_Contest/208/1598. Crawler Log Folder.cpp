class Solution {
public:
    int minOperations(vector<string>& logs) {
            stack<int>s;
            s.push(-1);
            for(int i=0;i<logs.size();i++)
            {
                     if(s.size()==1&&logs[i]=="../")
                            continue;
                    else if(s.size()>1&&logs[i]=="../")
                      s.pop();
                    else if(logs[i]=="./")
                            continue;
                    else
                    s.push(1);                        
    
            }
      
           if(s.size()>=1)
            return s.size()-1;
            return 0;
        
    }
};
