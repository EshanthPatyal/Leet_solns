class Solution {
public:
    int numRollsToTarget(int n, int m, int target) {
        const int mod = 1000000007;
        vector<vector<int>> dp(n+1,vector<int>(target+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){
                for(int k=1;k<=m;k++){
                    if(j>=k){
                        dp[i][j]+=dp[i-1][j-k];
                        dp[i][j]%=mod;
                    }
                }
            }
        }
        return dp[n][target];
    }
};