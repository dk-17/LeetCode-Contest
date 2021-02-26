class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int ans=0;
        int day=1;
        int i=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int n=apples.size();
        while(i<n || (!pq.empty())){
            
            if(i<n){
                pq.push({day+days[i],apples[i]});
                    i++;
            }
            
            while(!pq.empty() && pq.top().first<=day)
                pq.pop();
            
            if(!pq.empty()){
                auto temp=pq.top();
                pq.pop();
                ans++;
                temp.second--;
                if(temp.second>0)
                    pq.push(temp);
            }
            day++;
        }
        return ans;
        
    }
};
