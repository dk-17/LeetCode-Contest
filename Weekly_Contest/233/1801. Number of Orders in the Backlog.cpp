class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& o) {
        priority_queue<pair<int,int>> buy;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > sell;
        
        for(int i = 0; i < o.size(); i++){
            int price = o[i][0];
            int amount = o[i][1];
            int type = o[i][2];
            
            if(type == 0)
                buy.push({price,amount});
            else
                sell.push({price,amount});
            
            while(buy.size() && sell.size() && sell.top().first <= buy.top().first){
                int k = min(sell.top().second,buy.top().second);
                
                auto temp = buy.top();
                buy.pop();
                
                temp.second = temp.second - k;
                if(temp.second) buy.push(temp);
                
                temp = sell.top();
                sell.pop();
                
                temp.second = temp.second - k;
                if(temp.second) sell.push(temp);
                
            }
            
            
        }
        
        int ans = 0;
        int mod = 1e9 +7;
        while(!buy.empty()){
            ans  = (ans + buy.top().second) % mod;
            buy.pop();
        }
        while(!sell.empty()){
            ans  = (ans + sell.top().second) % mod;
            sell.pop();
        }
        
        return ans;
        
    }
};
