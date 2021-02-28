class Solution {
public:
    
    int Solve(vector<int>& a,vector<int>& b,int sum_a,int sum_b){
      
        int count=0;
        int l=a.size()*1;
        int r=b.size()*6;
        if(l>r) return -1;
        
        int i=a.size()-1;
        int j=0;
        while(i>=0 || j<b.size()){
            //cout<<"count= "<<count<<" "<<sum_a<<" "<<sum_b<<endl;
            if(sum_a<=sum_b) break;
            
            int change1 = -1;
            int change2 = -1;
            
            if(i>=0){
                change1= a[i]-1;
            }
            if(j<b.size())
                change2 = 6-b[j];
          
            if(change1>=change2){
                sum_a-=change1;
                i--;
            }
            else {
                sum_b+=change2 ;
                j++;
            }
            count++;
        }
        return count;
    }
    
    
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int sum1=0,sum2=0;
        for(int i=0;i<nums1.size();i++) sum1+=nums1[i];
        for(int j=0;j<nums2.size();j++) sum2+=nums2[j];
        
        if(sum1 == sum2) return 0;
        if(sum1>sum2)
            return Solve(nums1,nums2,sum1,sum2);
        
        return Solve(nums2,nums1,sum2,sum1);
        
    }
};
