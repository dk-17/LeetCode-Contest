class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,pair<int,int>>> pq;
        for(int i = 0; i < classes.size(); i++){
            int pass = classes[i][0];
            int total = classes[i][1];
          
            double delta = (double)(pass + 1)/(total + 1) - (double)(pass)/(total);
            pq.push({delta,{pass,total}});
        }
        
        while(extraStudents--){
            auto temp = pq.top();
            pq.pop();
            int pass = temp.second.first;
            int total = temp.second.second;
            pass ++;
            total ++;
            double delta = (double)(pass + 1)/(total+1) - (double)(pass)/(total);
            pq.push({delta,{pass,total}});
            
        }
        
        double ans = 0.0;
        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();
            ans += (double)(temp.second.first)/(temp.second.second);
        }
        return ans/classes.size();
        
    }
};
