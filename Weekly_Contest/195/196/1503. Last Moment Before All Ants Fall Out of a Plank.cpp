class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) 
    {
        if(right.size()==0&&left.size()==0)
            return 0;
        if(right.size()==0&&left.size()!=0)
        {
            sort(left.begin(),left.end());
            return left[left.size()-1];
        }
        if(left.size()==0&& right.size()!=0)
        {
            sort(right.begin(),right.end());
            return n-right[0];

        }
        sort(left.begin(),left.end());
        sort(right.begin(),right.end());
        int l=left[left.size()-1];
        int r=right[0];
        //cout<<"l="<<l<< " r"<<r <<endl;
        if(l-r==0)
            return n-min(l,r);
        else
        {
            int after=(l-r)/2;
            int x=max((l-after),(n-(r+after)));
            //cout<<"x="<<x<<endl;
            x+=after;
            
            //cout<<"r=="<<r<<endl;
            return (x);
        }
           return 0; 
        
    }
};
