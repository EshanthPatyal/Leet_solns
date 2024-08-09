class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& b) {
        int n=b.size();
        const int mod=1e9+7;
        vector<vector<int>> dirs {{1, 0}, {0, 1}, {1, 1}};
        vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        vector<vector<int>> path(n+1,vector<int> (n+1,0));
        b[0][0]='0';
        b[n-1][n-1]='0';
        path[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(b[i-1][j-1]=='X')continue;
                for(auto d:dirs){
                    int i1=i-d[0],j1=j-d[1];
                    int score=(b[i-1][j-1]-'0')+dp[i1][j1];
                    if(score>=dp[i][j] && path[i1][j1]>0){
                        path[i][j]= (dp[i][j]==score?path[i][j]:0) + path[i1][j1];
                        path[i][j]%=mod;
                        dp[i][j]=score;
                    }
                }
            }
        }
        if(path[n][n]==0){
            return {0,0};
        }
        return {dp[n][n],path[n][n]};
    }
};