class Solution {
public:
    int minCost(int m, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(m);
        vector<vector<int>> dp(cuts.size(),vector<int>(cuts.size(),0));
        int n=cuts.size();
        sort(cuts.begin(), cuts.end());
        for(int jump=2;jump<n;jump++){
            for(int i=0;i<n-jump;i++){
                int res=INT_MAX,j=i+jump;
                for(int k=i+1;k<j;k++){
                    res=min(res,dp[i][k]+dp[k][j]);
                }
                dp[i][j]=res+cuts[j]-cuts[i];
            }
        }
        return dp[0][n-1];
    }
};