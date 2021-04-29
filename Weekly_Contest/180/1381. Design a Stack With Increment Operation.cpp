class CustomStack {
public:
    vector<int> v;
    int j = 0;
    CustomStack(int maxSize) {
        v.resize(maxSize,0);
    }
    
    void push(int x) {
        if(j < 0) j = 0;
        if( j!= v.size()){
           v[j++] = x;
        }        
        
    }
    
    int pop() {
       j--;
       if( j < 0) return -1;
        return v[j];
    }
    
    void increment(int k, int val) {
        int n = v.size();
        n = min(k,n);
        for(int i = 0; i < n; i++)
            v[i]+= val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
