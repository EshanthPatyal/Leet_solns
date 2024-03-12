class Solution {
public:
    int helper(vector<int>& v,vector<int>& dp,int i,int n){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int take_curr=v[i]+helper(v,dp,i+2,n);
        int dont_take_curr=helper(v,dp,i+1,n);
        return dp[i]=max(take_curr,dont_take_curr);
    }
    int rob(vector<int>& v) {
        int n=v.size();
        vector<int>dp(n,-1);
        return helper(v,dp,0,n);
    }
};