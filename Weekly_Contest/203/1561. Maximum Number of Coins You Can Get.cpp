class Solution {
public:
    int maxCoins(vector<int>& piles)
    {
            sort(piles.begin(),piles.end(),greater<int>());
            int n=piles.size();
            int ans=0;
            int i=1;;
            while(i<n)
            {
                    ans+=piles[i];
                    i+=2;
                    n--;
            }
            return ans;
        
    }
};
