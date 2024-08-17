class Solution {
public:
    unordered_set<int> s;
    int f(int curr,int& x,int& a,int& b, bool flag,vector<vector<int>>&dp){
        if(curr==x)return 0;
        if(curr<0 || curr>7000 || s.find(curr)!=s.end()){
            return 1e9;
        }
        if(dp[curr][flag]!=-1)return dp[curr][flag];
        dp[curr][flag]=1+f(curr+a,x,a,b,false,dp);
        if(!flag){
            dp[curr][flag]=min(dp[curr][flag],1+f(curr-b,x,a,b,true,dp));
        }
        return dp[curr][flag];

        }
    int minimumJumps(vector<int>& fo, int a, int b, int x) {
        for(auto it:fo)s.insert(it);
        vector<vector<int>> dp(7100,vector<int>(2,-1));
        int t=f(0,x,a,b,false,dp);
        return t>=1e9?-1:t;
    }
};