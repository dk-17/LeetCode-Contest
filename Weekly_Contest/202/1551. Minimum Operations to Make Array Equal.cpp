class Solution {
public:
    int minOperations(int n) {
        int total  = 0;
        vector<int> v;
        for(int i = 1; i <= n*2 ;i+=2){
            total +=i;
            v.push_back(i);
        }
        
        int x = total/n;
        int ans = 0;
        int numberOfOperation = 0;
        for(int i = 0; i < v.size(); i++){
            if(v[i] < x){
                ans +=x - v[i];
            }
        }
        return ans;
        
    }
};

// another method;
class Solution {
public:
    int minOperations(int n) {
        int count=0;
          
            int i=1,j=(2*(n-1))+1;
            while(i<j)
            {
                    count+=(j-i)/2;
                    i+=2;
                    j-=2;
            }
            return count;
            
    }
};
