class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;
        if(a)
        pq.push({a,'a'});
        if(b)
        pq.push({b,'b'});
        if(c)
        pq.push({c,'c'});
        string s="";
       // cout<<"pq.size()="<<pq.size()<<endl;
        while(pq.size()>1){
          
            auto temp1 = pq.top();pq.pop();
            auto temp2 = pq.top();pq.pop();
            if(temp1.first >=2){
                s += temp1.second;
                s += temp1.second;
                temp1.first -= 2;
            }
            else{
                s +=temp1.second;
                temp1.first-=1;
            }
            
            if(temp2.first>=2 && temp2.first>=temp1.first){
                 s += temp2.second;
                 s += temp2.second;
                temp2.first -=2;
            }
            else{
                s +=temp2.second;
                temp2.first-=1;
            }
            if(temp1.first>0) pq.push(temp1);
            if(temp2.first>0) pq.push(temp2);
            //  cout<<"s="<<s<<endl;
        }
        
        if(pq.empty()) return s;
        if(pq.top().first>=2){
            s +=pq.top().second;
            s += pq.top().second;
        }
        else{
            s +=pq.top().second;
        }
        return s;
    }
};
