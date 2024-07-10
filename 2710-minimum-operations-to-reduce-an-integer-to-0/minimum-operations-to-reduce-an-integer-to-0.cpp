class Solution {
public:
    int minOperations(int n) {
        if(n==0)return 0;
        int l=floor(log2(n));
        int r=ceil(log2(n));
        l=n-pow(2,l);
        r=pow(2,r)-n;
        return 1+minOperations(min(l,r));
    }
};