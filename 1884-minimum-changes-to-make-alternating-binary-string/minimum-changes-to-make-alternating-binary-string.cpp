class Solution {
public:
    int minOperations(string s) {
        int a=0;
        int b=1;
        int run1=0,run2=0;
        for(int i=0;i<s.length();i++){
            run1+=a^(s[i]-'0');
            run2+=b^(s[i]-'0');
            b=(b+1)%2;
            a=(a+1)%2;
        }
        return min(run1,run2);
    }
};