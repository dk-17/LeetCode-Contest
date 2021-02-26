class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count_1=0;
        int count_0=0;
        for(int i=0;i<students.size();i++){
            if(students[i]==1)
                count_1++;
            if(students[i]==0)
                count_0++;
        }
        
        int n=sandwiches.size();
        int j=0;
        while(j<n ){
            if(sandwiches[j]==0){
                if(count_0>0){
                    count_0--;
                    j++;
                }
                else
                    break;
            }
            else{
                if(count_1>0){
                    count_1--;
                    j++;
                }
                else
                    break;
            }
        }
        return n-j;
        
        
        
        
    }
};
