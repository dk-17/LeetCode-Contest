class Solution {
public:
   static  bool compare(vector<int>& a,vector<int>& b){
        return ((a[1]-a[0])>(b[1]-b[0]));
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        int n=tasks.size();
        int total=0;
        sort(tasks.begin(),tasks.end(),compare);
        for(int i=0;i<n;i++)
            total+=tasks[i][0];
      
        int res=total;
        for(int i=0;i<n;i++){
         
            if(total<tasks[i][1])
                total+=tasks[i][1]-total;
            total-=tasks[i][0];
             
        }
        return total+res;
    }
};
