class Solution {
public:
    vector<int> closest(int num){
     
        for(int i = sqrt(num);i>0;i--){
          
            if(num%i == 0){
                return {i,num/i};
            }
        }
        return {0,0};
    }
    vector<int> closestDivisors(int num) {
        int x  = num+1;
        vector<int> one = closest(x);
        vector<int> two = closest(x+1);
        return (abs(one[0]-one[1]) > abs(two[0]-two[1]))? two:one;
        
    }
};
