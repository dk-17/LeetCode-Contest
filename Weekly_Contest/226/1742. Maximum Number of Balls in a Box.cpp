class Solution {
public:
    
    int inbox(int num){
        int sum=0;
        while(num){
            sum+=num%10;
            num/=10;
        }
        return sum;
    }
    
    int countBalls(int lowLimit, int highLimit) {
        int ans=INT_MIN;
        unordered_map<int,int> umap;
        int num=lowLimit;
        while(num<=highLimit){
            int index=inbox(num);
            //cout<<"index= "<<index<<endl;
            umap[index]++;
            if(ans<umap[index])
               ans=umap[index];
            num++;
            }
        return ans;
        
    }
};
