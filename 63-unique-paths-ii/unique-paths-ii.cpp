class Solution {
public:
    int f(int i,int j, vector<vector<int>> &dp,int m,int n,vector<vector<int>>& v){
        if(i==m-1 && j==n-1 && v[i][j]==0){
            return 1;
        }
        if(i>=m || j>=n || v[i][j]==1){
            return 0;
        }
        if(dp[i][j]!=0){
            return dp[i][j];
        }
        int right=f(i,j+1,dp,m,n,v);
        int down=f(i+1,j,dp,m,n,v);
        return dp[i][j]+=(right+down);
        


    }
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        int m=v.size();
        int n=v[0].size();
        // vector<vector<int>> dp(m,vector<int> (n,0));
        vector<vector<int>> dp(m,vector<int> (n,0));
        dp[0][0]=(v[0][0]==0);
        for(int i=1;i<m;i++){
            if(v[i][0]==0)dp[i][0]=dp[i-1][0];
            else dp[i][0]=0;        
        }
        for(int i=1;i<n;i++){
            if(v[0][i]==0)dp[0][i]=dp[0][i-1];
            else dp[0][i]=0;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(v[i][j]==1)dp[i][j]==0;
                else dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];        
        // return f(0,0,dp,m,n,v);
    }
};