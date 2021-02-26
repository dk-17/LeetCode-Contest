class Solution {
public:
    int totalMoney(int n) {
        int sum=0;
        int start=0;
        for(int i=1;i<=n/7;i++){
            start=i;
            for(int j=0;j<7;j++){
                sum+=start;
                start++;
            }
        }
        
        if(n%7!=0){
            start=(n/7)+1;
            int count=(n%7);
            while(count--){
                sum+=start;
                start++;
            }
        }
        return sum;
    }
};
