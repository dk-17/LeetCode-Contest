int mod = 1000000007;
class Solution {
public:
    long long int getBinaryLength(long long int n){
       long long  int length=0;
        while(n>0){
            length+=1;
            n/=2;
        }
        return length;
    }
    
    
    
    long long int concat(long long int n,long long int i){
        long long int length=getBinaryLength(i);
        return ((n<<length)+i)%mod;
    }
    int concatenatedBinary(int n) {
        long long int num=1;
        for(int i=2;i<=n;i++){
            num=(concat(num,i))%mod;
          //  cout<<"num= "<<num<<endl;
        }
        return num;
    }
};
