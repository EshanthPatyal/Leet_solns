class Solution {
public:
    int mod=1e9+7;
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n+1,vector<int>(k+1,0));
        for(int i=0;i<=n;i++)dp[i][0]=1;
        for(int i=1;i<=n;i++){
            vector<long long> prev(k+2,0);
            for(int j=0;j<=k;j++){
                prev[j+1]=prev[j]+dp[i-1][j];
            }
            for(int j=1;j<=k;j++){

                dp[i][j]=(prev[j+1]-prev[max(0,j-i+1)])%mod;
            }
        }
        // for(int i=0;i<=n;i++){
        //     // vector<int> prev(k+2,0);
        //     // for(int j=1;j<=k;j++){
        //     //     prev[j+1]=prev[j]+dp[i-1][j];
        //     // }
        //     for(int j=1;j<=k;j++){
        //         cout<<dp[i][j]<<" ";
        //     //     dp[i][j]=prev[j+1]-prev[max(0,j-i+1)];
        //     }
        //     cout<<endl;
        // }

        return dp[n][k];
    }
};