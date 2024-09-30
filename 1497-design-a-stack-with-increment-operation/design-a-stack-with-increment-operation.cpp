class CustomStack {
public:
    vector<int> v;
    int i=1;
    CustomStack(int maxSize) {
        v.assign(maxSize+1,-1);
    }
    
    void push(int x) {
        if(i==v.size())return;
        if(i==0)i++;
        v[i]=x;
        i++;
    }
    
    int pop() {
        if(i==0)return -1;
        i--;
        int a=v[i];
        v[i]=-1;
        return a;
    }
    
    void increment(int k, int val) {
        for(int j=1;j<min(k+1,(int)v.size());j++){
            if(v[j]==-1)return;
            v[j]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */