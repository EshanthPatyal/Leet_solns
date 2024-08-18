class Solution {
public:
    long long maxEnergyBoost(vector<int>& a, vector<int>& b) {
        int n=a.size();
        vector<vector<long long>> dp(n+1,vector<long long>(2,0));
        dp[0][0]=a[0];
        dp[0][1]=b[0];
        for(int i=1;i<n;i++){
            dp[i][0]=a[i]+dp[i-1][0];
            dp[i][1]=b[i]+dp[i-1][1];
            if(i>1){
                dp[i][0]=max(dp[i][0],a[i]+dp[i-2][1]);
                dp[i][1]=max(dp[i][1],b[i]+dp[i-2][0]);
            }
        }
        return max(dp[n-1][0],dp[n-1][1]);
    }
};