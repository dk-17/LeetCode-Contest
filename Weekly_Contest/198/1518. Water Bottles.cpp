class Solution {
public:
    int numWaterBottles(int num, int ex) {
        int count = num;
        while(num){
            if(num < ex) break;
            
            num = (num -ex)+1;
            
           if(num < 0) break;
            count++;
        }
        return count;
        
    }
};
