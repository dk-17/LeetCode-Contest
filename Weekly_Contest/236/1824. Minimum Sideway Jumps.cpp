class Solution {
public:
    int minSideJumps(vector<int>& ob) {
        queue<int> q1,q2,q3;
        int lane = 2;
        int n = ob.size();

        
        for(int i = 0; i< ob.size(); i++){
            if(ob[i]==1) q1.push(i);
             if(ob[i]==2)  q2.push(i);
            if(ob[i] == 3)  q3.push(i);
         }
        //if there is no obstacle in the lane then it should last add at n index. The point it should stop since we are picking that lane which is as far as possible!
        q1.push(n);
        q2.push(n);
        q3.push(n);
        
        int count  = 0;
        for(int i = 0; i< ob.size()-1; i++){
        
            if(lane == 1 && (!q1.empty()) && q1.front() == i+1){
                count++;
                lane =  (q2.front() > q3.front()) ? 2 : 3;
            }
            if(lane == 2 && (!q2.empty()) && q2.front() == i+1 ){
                 count++;
                 lane = (q1.front() > q3.front())? 1:3;      
            }
              if(lane == 3&& (!q3.empty()) && q3.front() == i+1 ){
                   count++;
                   lane = (q1.front() > q2.front()) ? 1:2;
            }
            
            if(!q1.empty() && q1.front()<=i) q1.pop();
            if(!q2.empty() && q2.front()<=i) q2.pop();
            if(!q3.empty() && q3.front()<=i) q3.pop();
        }
        return count;
    }
};
