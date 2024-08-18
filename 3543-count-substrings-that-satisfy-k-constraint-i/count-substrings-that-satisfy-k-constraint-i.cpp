class Solution {
public:
    int countKConstraintSubstrings(string s, int t) {
        int n=s.size();
        int ret=0;
        for(int i=0;i<n;i++) {
            for(int j=i;j<n;j++) {
                int a=0,b=0;
                for(int k=i;k<=j;k++) {
                    if(s[k]=='0')a++;
                    else b++;
                }
                if(a<=t || b<=t)
                    ret++;
            }
        }
        return ret;
    }
};