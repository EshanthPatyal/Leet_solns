class Solution {
public:
    int n;
    int recur(vector<int>& c,vector<int>& t,vector<vector<int>>& dp,int i,int time){
        if(time<=0)return 0;
        if(i==c.size())return 1e9;
        if(dp[i][time]!=-1)return dp[i][time];
        int nt=recur(c,t,dp,i+1,time);
        int tk=c[i]+recur(c,t,dp,i+1,time-t[i]-1);
        return dp[i][time]=min(nt,tk);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        vector<vector<int>> dp(cost.size(),vector<int>(time.size()+1,-1));
        n=cost.size();
        return recur(cost,time,dp,0,time.size());

    }
};