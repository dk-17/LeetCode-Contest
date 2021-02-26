 bool sortbysec(const vector<int>& a,vector<int>& b){
        return a[1]>b[1];
    }
    
class Solution {
public:
   
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),sortbysec);
        // for(int i=0;i<boxTypes.size();i++){
        //     cout<<boxTypes[i][0]<<" "<<boxTypes[i][1]<<endl;
        // }
        int ans=0;
        for(int i=0;i<boxTypes.size();i++){
            int box=boxTypes[i][0];
            int weight=boxTypes[i][1];
            if(box<=truckSize){
                ans+=box*weight;
                truckSize-=box;
            }
            else{
                if(truckSize!=0){
                ans+=weight*truckSize;
                    truckSize=0;
                break;}
            }
            if(truckSize==0)
                break;
        }
        return ans;
    }
};
