class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n=encoded.size()+1;
        int total_xor=0;
        for(int i=1;i<=n;i++)
            total_xor^=i;
        int even_xor=0;
        for(int i=1;i<encoded.size();i+=2){
            even_xor^=encoded[i];
        }
        int first=total_xor ^ even_xor;
        vector<int> ans;
        ans.push_back(first);
        for(int i=0;i<encoded.size();i++){
            ans.push_back(ans.back() ^ encoded[i]);
        }
        return ans;
        
        
    }
};
