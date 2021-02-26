class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int curr_height=0;
        int next_height=0;
        int ans=0;
        for(int i=0;i<gain.size();i++){
            next_height=gain[i]+curr_height;
            if(ans<next_height)
                ans=next_height;
            curr_height=next_height;
        }
        return ans;
    }
};
