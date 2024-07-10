class Solution {
public:
    int countSquares(vector<vector<int>>& v) {
        int m=v.size(),n=v[0].size();
        vector<vector<int>> dp(m+1,vector<int> (n+1,0));
        int res=0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(v[i-1][j-1]){
                    dp[i][j]=1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
                    res+=dp[i][j];
                }
            }
        }
        return res;
    }
};