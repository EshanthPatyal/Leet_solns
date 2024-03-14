class Solution {
public:
    int f(int i,int j, vector<vector<int>> &dp,int m,int n){
        if(i==0 && j==0){
            return 1;
        }
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=0){
            return dp[i][j];
        }
        dp[i][j]+=f(i-1,j,dp,m,n);
        dp[i][j]+=f(i,j-1,dp,m,n);
        return dp[i][j];

    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int> (n,0));
        return f(m-1,n-1,dp,m,n);
    }
};