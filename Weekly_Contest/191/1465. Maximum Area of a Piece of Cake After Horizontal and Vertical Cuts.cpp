class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        hc.push_back(h);
        vc.push_back(w);
        sort(hc.begin(),hc.end());
        sort(vc.begin(),vc.end());
        int max_h = hc[0];
        int max_v = vc[0];
        int mod = 1000000007;
        long ans = 0;
        for(int i = 1; i< hc.size();i++)
            max_h = max(max_h,(hc[i]-hc[i-1])) ;
        for(int i = 1; i < vc.size();i++)
            max_v = max(max_v,(vc[i]-vc[i-1]));
        //cout<<"max_h="<<max_h<<" max_v= "<<max_v<<endl;
         long _h= max_h;
        long _v = max_v;
        ans = (_h*_v)%mod;
        return ans;
    }
};
