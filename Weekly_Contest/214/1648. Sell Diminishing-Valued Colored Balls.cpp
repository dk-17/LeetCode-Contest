int mod=1000000007;
class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        priority_queue<int> pq;
        for(int i=0;i<inventory.size();i++)
            pq.push(inventory[i]);
        
        int ans=0;
        while(orders--){
            ans=(ans+pq.top())%mod;
            pq.push(pq.top()-1);
            pq.pop();
        }
        return ans;
    }
};
