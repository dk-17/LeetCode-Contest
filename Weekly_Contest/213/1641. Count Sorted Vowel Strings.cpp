class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> fib;
        fib.push_back(0);
        fib.push_back(5);
        fib.push_back(15);
        for(int i=2;i<=n;i++){
            fib.push_back(fib[i-1]*10);
            
        }
        return fib[n];
        
    }
};
