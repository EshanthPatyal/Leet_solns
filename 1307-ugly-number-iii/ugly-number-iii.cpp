class Solution {
public:
    int nthUglyNumber(int n, int a1, int b1, int c1) {
        int low = 1, high = 2 * (int) 1e9;
        long a = long(a1), b = long(b1), c = long(c1);
        long ab = a * b / __gcd(a, b);
        long bc = b * c / __gcd(b, c);
        long ac = a * c / __gcd(a, c);
        long abc = a * bc / __gcd(a, bc);
        while(low < high) {
            int mid = low + (high - low)/2;
            int cnt = mid/a + mid/b + mid/c - mid/ab - mid/bc - mid/ac + mid/abc;
            if(cnt < n) 
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
};