class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& c) {
        double ans=0;
        int waiting=0;
        int time_taken=0;
        int n=c.size();
        time_taken = c[0][0]+c[0][1];
        waiting=time_taken-c[0][0];
        ans+=waiting;
        for(int i=1;i<c.size();i++){
            if(time_taken>c[i][0]){
                time_taken+=c[i][1];
                waiting=time_taken-c[i][0];
                ans+=waiting;
            }
            else{
                time_taken+=c[i][0]-time_taken+c[i][1];
                ans+=c[i][1];
                
            }
        }
        return ans/n;
        
        
    }
};
