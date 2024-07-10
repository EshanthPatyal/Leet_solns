class Solution {
public:
    int maxMoves(vector<vector<int>>& g) {
        int m=g.size(),n=g[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        int out=0;
        for(int j=n-2;j>=0;j--){
            for(int i=m-1;i>=0;i--){
                if(g[i][j+1]>g[i][j]){
                    dp[i][j]=max(dp[i][j],1+dp[i][j+1]);
                }
                if(i+1<m  && g[i+1][j+1]>g[i][j]){
                    dp[i][j]=max(dp[i][j],1+dp[i+1][j+1]);
                }
                if(i>0 && g[i-1][j+1]>g[i][j]){
                    dp[i][j]=max(dp[i][j],1+dp[i-1][j+1]);
                }
                if(j==0)out=max(out,dp[i][j]);
            }
        }
        return out;
    }
};