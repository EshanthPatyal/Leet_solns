class Solution {
public:
    int integerBreak(int n) {
    //  return 0;   
        vector<int> dp(n+5,1);
        for(int i=1;i<=n-1;i++){
            // dp[i]=max(2*dp[i-2],3*dp[i-3]);
            for(int j=1;j<=n;j++){
                if(i<=j)dp[j]=max(dp[j],dp[j-i]*i);
            }
        }
        return dp[n];
    }
};