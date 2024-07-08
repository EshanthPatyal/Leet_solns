class Solution {
public:
    int recur(vector<int>&dp,int idx,vector<int>&p){
        if(idx>=p.size())return 0;
        if(dp[idx]!=-1)return dp[idx];
        int cur=INT_MAX;
        for(int j=idx+1;j<=2*idx+2;j++){
            cur=min(cur,recur(dp,j,p));
        }
        return dp[idx]=cur+p[idx];

    }
    int minimumCoins(vector<int>& prices) {
        int n=prices.size();
        vector<int> dp(n,-1);
        return recur(dp,0,prices);
    }
};