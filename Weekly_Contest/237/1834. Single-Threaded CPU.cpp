class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        for(int i =0; i< tasks.size();i++){
            tasks[i].push_back(i);
        }
        sort(tasks.begin(),tasks.end());
        long time = 0;
        int i = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
        vector<int> ans;
        int n = tasks.size();
        while(i<n || pq.size()){
            if(pq.empty()){
                time = max(time,(long)tasks[i][0]);
            }
            while(i<n && time>=tasks[i][0]){
                pq.push({tasks[i][1],tasks[i][2]});
                i++;
            }
            auto temp = pq.top();
            pq.pop();
            time +=temp.first;
            ans.push_back(temp.second);
        }
        return ans;
        
    }
};
