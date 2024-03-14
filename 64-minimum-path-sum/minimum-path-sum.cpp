class Solution {
public:
    int f(int i,int j,int m,int n,vector<vector<int>>& dp, vector<vector<int>>&v){
        if(i==m-1 && j==n-1){
            return v[i][j];
        }
        if(i>=m || j>=n){
            return 1000000;
        }
        if(dp[i][j]!=INT_MAX){
            return dp[i][j];
        }

        int left=v[i][j]+f(i+1,j,m,n,dp,v);
        int right=v[i][j]+f(i,j+1,m,n,dp,v);
        return dp[i][j]=min(dp[i][j],min(right,left));

    }
    int minPathSum(vector<vector<int>>& v) {
        int m=v.size();
        int n=v[0].size();
        vector<vector<int>> dp(m,vector<int> (n,INT_MAX));
        return f(0,0,m,n,dp,v);
    }
};