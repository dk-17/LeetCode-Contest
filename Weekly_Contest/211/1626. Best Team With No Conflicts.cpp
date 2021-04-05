class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> age_score;
        for(int i = 0; i < ages.size(); i++){
        age_score.push_back({ages[i],scores[i]});
        }
        int ans = 0;
        sort(age_score.begin(),age_score.end(),greater<>());
        vector<int>dp(ages.size()+1,0);
        for(int i  =0;i < ages.size();i++){
            int score = age_score[i].second;
            dp[i] = score;
            for(int j = 0; j<i; j++){
                if(age_score[j].second >= age_score[i].second)
                    dp[i]= max(dp[i],dp[j] + score);
            }
            ans = max(ans,dp[i]);
        }
        return ans;
        
    }
};
