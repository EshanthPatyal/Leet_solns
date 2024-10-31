class Solution {
public:
    long long dp[100][100][100];
    long long recur(int i, int j, int k, vector<int>& r, vector<vector<int>>& f)
    {
        if (i<0) return 0;
        if (j<0) return 1LL<<40;
        if (dp[i][j][k]!=-1) return dp[i][j][k];
        int xR=r[i], xF=f[j][0];
        long long not_take=recur(i, j-1, 0, r, f);
        long long take=(k<f[j][1])?abs(xR-xF)+recur(i-1, j, k+1, r, f):1LL<<40;
        return dp[i][j][k]=min(not_take,  take);

    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        
        int n=robot.size(), m=factory.size();
        memset(dp, -1, sizeof(dp));
        return recur(n-1, m-1, 0, robot, factory);
    }
};