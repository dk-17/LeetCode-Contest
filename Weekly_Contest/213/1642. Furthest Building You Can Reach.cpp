class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int i=0;
        while(i<heights.size()-1){
          //  cout<<"i="<<i<<endl;
            if(heights[i+1]<=heights[i])
            {
                i++;
                continue;
            }
            else if(heights[i+1]>heights[i]){
                {
                    if(heights[i+1]-heights[i]>bricks)
                    {
                        if(ladders)
                        {
                            ladders--;
                            i++;   
                        }
                        else 
                            break;
                        
                    }
                    else {
                        if(heights[i+1]-heights[i]<=bricks){
                            bricks-=heights[i+1]-heights[i];
                            if(bricks<0)
                                break;
                            i++;
                            
                        }
                    }
                }
            }
        }
        return i;
        
    }
};
