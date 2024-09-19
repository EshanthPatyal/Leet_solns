class Solution {
public:
    long long f(vector<int>&a,vector<int>&b,vector<vector<long long>>&dp,int i,int l){
        if(l==0)return 0;
        if(i==b.size())return -1e16;
        if(dp[i][l]==LLONG_MIN){
            dp[i][l]=max(f(a,b,dp,i+1,l),a[4-l]*1LL*b[i] + f(a,b,dp,i+1,l-1));   
        } 
        return dp[i][l];
    }
    long long maxScore(vector<int>& a, vector<int>& b) {
        int n=b.size();
        vector<vector<long long>> dp(n,vector<long long>(5,LLONG_MIN));
        return f(a,b,dp,0,4);
    }
};