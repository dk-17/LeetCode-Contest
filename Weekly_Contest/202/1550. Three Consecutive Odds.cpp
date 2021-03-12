class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
            int count=0;
            int n=arr.size();
            for(int i=0;i<n;i++)
            {
                    count=0;
                    for(int j=i;j<n;j++){
                            if((arr[j]%2)!=0)
                            {
                                  count++;
                                    if(count==3)
                                            return true;
                            }
                            else
                            {
                                    break;
                            }
                    }
                    
            }
            return false;
        
    }
};
