class Solution {
public:
    long long minEnd(int n, int x) {
        long long res = x;
        for (long long bx = 1, bn = 1; bn < n; bx <<= 1)
            if ((bx & x) == 0) {
                if (bn & (n - 1))
                    res += bx;
                bn <<= 1;
            }
        return res;
    }
};