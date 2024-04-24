class Solution {
public:
    int tribonacci(int n) {
        vector<int> v(38,0);
        int a=0,b=1,
        c=1,d=0;
        if(n==0)return 0;
        if(n<3){
            return 1;
        }

        for(int i=3; i<=n; i++) {
            v[i] = v[i-1] + v[i-2] + v[i-3];
            d=a+b+c;
            a=b;
            b=c;
            c=d;
        }
        return d;        
    }
};